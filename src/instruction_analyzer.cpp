#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <cstdint>

struct FunctionInfo {
    std::string dll_name;
    std::string function_name;
    uintptr_t address;
    bool is_forwarded;
    
    FunctionInfo() : address(0), is_forwarded(false) {}
    
    FunctionInfo(const std::string& dll, const std::string& func, uintptr_t addr, bool forwarded = false)
        : dll_name(dll), function_name(func), address(addr), is_forwarded(forwarded) {}
};

struct InstructionInfo {
    std::string module_name;
    uintptr_t address;
    std::string disassembly;
    
    InstructionInfo() : address(0) {}
    
    InstructionInfo(const std::string& module, uintptr_t addr, const std::string& disasm)
        : module_name(module), address(addr), disassembly(disasm) {}
};

class FunctionLookup {
private:
    std::unordered_map<uintptr_t, FunctionInfo> address_to_function;
    std::vector<FunctionInfo> all_functions;
    
    // Sorted vector for binary search in findFunctionContaining
    std::vector<std::pair<uintptr_t, size_t>> sorted_addresses; // address -> index in all_functions
    bool sorted_addresses_valid = false;
    
    // Cache for repeated address lookups
    mutable std::unordered_map<uintptr_t, FunctionInfo*> containing_cache;
    
    // Helper function to convert hex string to uintptr_t
    uintptr_t hexStringToAddress(const std::string& hex_str) {
        std::stringstream ss;
        uintptr_t address;
        
        // Remove "0x" prefix if present
        std::string clean_hex = hex_str;
        if (clean_hex.length() > 2 && (clean_hex.substr(0, 2) == "0x" || clean_hex.substr(0, 2) == "0X")) {
            clean_hex = clean_hex.substr(2);
        }
        
        ss << std::hex << clean_hex;
        ss >> address;
        return address;
    }
    
    // Helper function to trim whitespace
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t\r\n");
        return str.substr(first, (last - first + 1));
    }
    
    // Helper function to check if string ends with suffix
    bool endsWith(const std::string& str, const std::string& suffix) const {
        if (str.length() >= suffix.length()) {
            return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
        }
        return false;
    }
    
    // Build sorted addresses for binary search
    void buildSortedAddresses() {
        if (sorted_addresses_valid) return;
        
        sorted_addresses.clear();
        sorted_addresses.reserve(all_functions.size());
        
        for (size_t i = 0; i < all_functions.size(); ++i) {
            sorted_addresses.push_back({all_functions[i].address, i});
        }
        
        std::sort(sorted_addresses.begin(), sorted_addresses.end());
        sorted_addresses_valid = true;
        containing_cache.clear(); // Clear cache when rebuilding
    }

public:
    // Helper function to check if module is an executable
    bool isExecutable(const std::string& module_name) const {
        std::string lower_module = module_name;
        std::transform(lower_module.begin(), lower_module.end(), lower_module.begin(), ::tolower);
        return endsWith(lower_module, ".exe");
    }
    
    // Parse instruction line in format: module_name!address disassembly
    InstructionInfo parseInstructionLine(const std::string& line) {
        InstructionInfo inst_info;
        
        // Find the exclamation mark that separates module from address
        size_t exclamation_pos = line.find('!');
        if (exclamation_pos == std::string::npos) {
            return inst_info; // Invalid format
        }
        
        // Extract module name
        inst_info.module_name = line.substr(0, exclamation_pos);
        
        // Find the space that separates address from disassembly
        size_t space_pos = line.find(' ', exclamation_pos);
        if (space_pos == std::string::npos) {
            return inst_info; // Invalid format
        }
        
        // Extract address
        std::string address_str = line.substr(exclamation_pos + 1, space_pos - exclamation_pos - 1);
        inst_info.address = hexStringToAddress(address_str);
        
        // Extract disassembly
        inst_info.disassembly = trim(line.substr(space_pos + 1));
        
        return inst_info;
    }
    
    // Load functions from the log file
    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return false;
        }
        
        // Reserve space to avoid frequent reallocations
        all_functions.reserve(10000);
        address_to_function.reserve(10000);
        
        std::string line;
        std::string current_module;
        int functions_loaded = 0;
        
        while (std::getline(file, line)) {
            // Skip empty lines and comments early
            if (line.empty() || line[0] == '#') {
                continue;
            }
            
            // Check for module header (e.g., "Module 1: dynamorio.dll")
            if (line.find("Module ") == 0) {
                size_t colon_pos = line.find(": ");
                if (colon_pos != std::string::npos) {
                    current_module = line.substr(colon_pos + 2);
                    std::cout << "Processing module: " << current_module << std::endl;
                }
                continue;
            }
            
            // Parse function lines (e.g., "0x000000007117aa42 dynamorio.dll!NtCreateSection (forwarded)")
            if (line.find("0x") == 0 && !current_module.empty()) {
                size_t first_space = line.find(' ');
                if (first_space == std::string::npos) continue;
                
                std::string address_str = line.substr(0, first_space);
                std::string function_info = trim(line.substr(first_space + 1));
                
                // Parse function info
                size_t exclamation_pos = function_info.find('!');
                if (exclamation_pos != std::string::npos) {
                    std::string dll_name = function_info.substr(0, exclamation_pos);
                    std::string func_part = function_info.substr(exclamation_pos + 1);
                    
                    // Check if forwarded
                    bool is_forwarded = endsWith(func_part, "(forwarded)");
                    std::string function_name = func_part;
                    
                    if (is_forwarded) {
                        // Remove " (forwarded)" from function name
                        function_name = trim(func_part.substr(0, func_part.length() - 12));
                    }
                    
                    // Convert address
                    uintptr_t addr = hexStringToAddress(address_str);
                    
                    // Create function info
                    FunctionInfo func_info(dll_name, function_name, addr, is_forwarded);
                    
                    // Add to our data structures
                    address_to_function[addr] = func_info;
                    all_functions.push_back(std::move(func_info));
                    functions_loaded++;
                }
            }
        }
        
        file.close();
        std::cout << "Loaded " << functions_loaded << " functions from " << all_functions.size() << " modules" << std::endl;
        
        // Invalidate sorted addresses so they get rebuilt on first use
        sorted_addresses_valid = false;
        
        return functions_loaded > 0;
    }
    
    // Find function that contains this address (optimized with binary search and caching)
    FunctionInfo* findFunctionContaining(uintptr_t address) {
        // Check cache first
        auto cache_it = containing_cache.find(address);
        if (cache_it != containing_cache.end()) {
            return cache_it->second;
        }
        
        // Build sorted addresses if needed
        buildSortedAddresses();
        
        // Binary search to find the function that contains this address
        auto it = std::upper_bound(sorted_addresses.begin(), sorted_addresses.end(), 
                                   std::make_pair(address, SIZE_MAX));
        
        FunctionInfo* result = nullptr;
        if (it != sorted_addresses.begin()) {
            --it;
            size_t func_index = it->second;
            uintptr_t func_addr = it->first;
            
            // Check if the distance is reasonable (within 64KB of function start)
            if (address >= func_addr && (address - func_addr) < 0x10000) {
                result = &all_functions[func_index];
            }
        }
        
        // Cache the result (even if nullptr)
        containing_cache[address] = result;
        
        return result;
    }
    
    // Print function info in single line format
    void printFunctionInfoOneLine(const FunctionInfo& func, std::ostream& output = std::cout) const {
        output << "Address: 0x" << std::hex << std::uppercase << func.address << std::dec << " | "
               << "DLL: " << func.dll_name << " | "
               << "Function: " << func.function_name;
        if (func.is_forwarded) {
            output << " (forwarded)";
        }
        output << std::endl;
    }
    
    // Print statistics
    void printStats() const {
        std::cout << "=== Function Lookup Statistics ===" << std::endl;
        std::cout << "Total functions loaded: " << all_functions.size() << std::endl;
        std::cout << "=============================" << std::endl;
    }
};

// Main function - analyzes instruction trace
int main() {
    std::ofstream called_funcs("api_calls_detected.log");
    if (!called_funcs.is_open()) {
        std::cerr << "Can't open output file api_calls_detected.log" << std::endl;
        return 1;
    }

    FunctionLookup lookup;
    
    // Load functions from the log file
    std::cout << "Loading functions from all_modules_functions.log..." << std::endl;
    if (!lookup.loadFromFile("all_modules_functions.log")) {
        std::cerr << "Failed to load functions from all_modules_functions.log" << std::endl;
        std::cerr << "Make sure to run the DynamoRIO tracer first!" << std::endl;
        return 1;
    }
    
    // Print statistics
    lookup.printStats();
    
    // Process instructions file
    std::cout << "\nProcessing instructions.log..." << std::endl;
    const std::string instr_name = "instructions.log";
    std::ifstream instr_file(instr_name);
    if (!instr_file.is_open()) {
        std::cerr << "Error: Cannot open file " << instr_name << std::endl;
        std::cerr << "Make sure to run the DynamoRIO tracer first!" << std::endl;
        return 1;
    }
    
    std::string line;
    InstructionInfo prev_instruction;
    bool first_instruction = true;
    size_t processed_count = 0;
    size_t logged_functions = 0;
    
    called_funcs << "# API Calls Detected from Instruction Trace" << std::endl;
    called_funcs << "# Format: Previous instruction (exe) -> Current function (dll)" << std::endl;
    called_funcs << "# Generated by instruction_analyzer.exe" << std::endl << std::endl;
    
    // Process instructions in batches for better performance
    while (std::getline(instr_file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // Parse current instruction
        InstructionInfo current_instruction = lookup.parseInstructionLine(line);
        if (current_instruction.address == 0) {
            continue; // Invalid line format
        }
        
        // Check if current instruction is in a DLL and previous was from an .exe
        if (!first_instruction && 
            !current_instruction.module_name.empty() &&
            !prev_instruction.module_name.empty()) {
            
            // Current instruction is in DLL, previous was from exe
            if (!lookup.isExecutable(current_instruction.module_name) &&
                lookup.isExecutable(prev_instruction.module_name)) {
                
                // Find the function that contains the current address
                FunctionInfo* result = lookup.findFunctionContaining(current_instruction.address);
                if (result) {
                    called_funcs << "=== API CALL DETECTED ===" << std::endl;
                    called_funcs << "From EXE: " << prev_instruction.module_name 
                               << "!0x" << std::hex << prev_instruction.address << std::dec << std::endl;
                    called_funcs << "To DLL Function: ";
                    lookup.printFunctionInfoOneLine(*result, called_funcs);
                    called_funcs << "Instruction: " << line << std::endl;
                    called_funcs << std::endl;
                    
                    logged_functions++;
                }
            }
        }
        
        // Update previous instruction for next iteration
        prev_instruction = current_instruction;
        first_instruction = false;
        
        // Progress indicator
        if (++processed_count % 50000 == 0) {
            std::cout << "Processed " << processed_count << " instructions, detected " 
                     << logged_functions << " API calls..." << std::endl;
        }
    }
    
    instr_file.close();
    called_funcs.close();
    
    std::cout << "\n=== ANALYSIS COMPLETE ===" << std::endl;
    std::cout << "Processed " << processed_count << " instructions." << std::endl;
    std::cout << "Detected " << logged_functions << " API calls from exe to DLLs." << std::endl;
    std::cout << "Results saved to: api_calls_detected.log" << std::endl;
    
    return 0;
}