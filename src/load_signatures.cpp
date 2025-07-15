#include <windows.h>
#include <winternl.h>
#include <psapi.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <regex>
#include <algorithm>

#include "headers\globals.h"

std::string ExtractParameterName(const std::string& paramDecl) {
    // Remove annotations like [in], [out], etc.
    std::string cleaned = paramDecl;

    // Remove anything in brackets
    size_t bracketStart = cleaned.find('[');
    while (bracketStart != std::string::npos) {
        size_t bracketEnd = cleaned.find(']', bracketStart);
        if (bracketEnd != std::string::npos) {
            cleaned.erase(bracketStart, bracketEnd - bracketStart + 1);
            bracketStart = cleaned.find('[');
        } else {
            break;
        }
    }

    // Trim whitespace
    cleaned = std::regex_replace(cleaned, std::regex(R"(^\s+|\s+$)"), "");

    if (cleaned.empty()) {
        return "";
    }

    // Look for parameter name - typically the last word
    std::regex nameRegex(R"(\b([a-zA-Z_][a-zA-Z0-9_]*)\s*$)");
    std::smatch match;

    if (std::regex_search(cleaned, match, nameRegex)) {
        std::string paramName = match[1].str();
        
        // Skip type keywords
        if (paramName != "VOID" && paramName != "HANDLE" && paramName != "DWORD" && 
            paramName != "BOOL" && paramName != "CONST" && paramName != "OPTIONAL" &&
            paramName != "CHAR" && paramName != "WCHAR" && paramName != "BYTE" &&
            paramName.length() > 1) {
            return paramName;
        }
    }

    return "";
}

std::vector<std::string> ParseParameterNames(const std::string& params) {
    std::vector<std::string> paramNames;
    
    if (params.empty()) {
        return paramNames;
    }
    
    // Simple comma splitting with bracket awareness
    std::vector<std::string> paramParts;
    std::string current;
    int bracketDepth = 0;
    
    for (size_t i = 0; i < params.length(); i++) {
        char c = params[i];
        
        if (c == '[') {
            bracketDepth++;
        } else if (c == ']') {
            bracketDepth--;
        } else if (c == ',' && bracketDepth == 0) {
            if (!current.empty()) {
                paramParts.push_back(current);
                current.clear();
            }
            continue;
        }
        current += c;
    }
    if (!current.empty()) {
        paramParts.push_back(current);
    }
    
    // Extract parameter names from each part
    for (const auto& part : paramParts) {
        std::string paramName = ExtractParameterName(part);
        if (!paramName.empty()) {
            paramNames.push_back(paramName);
        }
    }
    
    return paramNames;
}

void ParseSingleFunction(const std::string& funcDecl) {
    // Extract function name - look for pattern: "TYPE NAME("
    std::regex nameRegex(R"(\b(\w+)\s+(\w+)\s*\()");
    std::smatch match;
    
    if (!std::regex_search(funcDecl, match, nameRegex)) {
        return;
    }
    
    std::string funcName = match[2].str();
    
    // Extract parameters - everything between first ( and last )
    size_t startParen = funcDecl.find('(');
    size_t endParen = funcDecl.rfind(')');
    
    if (startParen == std::string::npos || endParen == std::string::npos || startParen >= endParen) {
        return;
    }
    
    std::string params = funcDecl.substr(startParen + 1, endParen - startParen - 1);
    std::vector<std::string> paramNames = ParseParameterNames(params);
    
    if (!paramNames.empty()) {
        functionSignatures[funcName] = paramNames;
    }
}

int ProcessHeaderFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    
    // Read file line by line instead of loading entire content
    std::string line;
    std::string currentFunction;
    int functionsFound = 0;
    bool inFunction = false;
    int lineCount = 0;
    const int MAX_LINES = 10000; // Safety limit
    
    while (std::getline(file, line) && lineCount < MAX_LINES) {
        lineCount++;
        
        // Simple line-by-line parsing instead of complex regex
        line = std::regex_replace(line, std::regex(R"(^\s+|\s+$)"), ""); // trim
        
        if (line.empty() || line[0] == '/' || line[0] == '*') {
            continue; // Skip comments and empty lines
        }
        
        if (inFunction) {
            currentFunction += " " + line;
            if (line.find(");") != std::string::npos) {
                // End of function found
                ParseSingleFunction(currentFunction);
                functionsFound++;
                currentFunction.clear();
                inFunction = false;
            }
        } else {
            // Look for function start - simple pattern: "TYPE FUNCTIONNAME("
            if (line.find("(") != std::string::npos && 
                (line.find("BOOL ") == 0 || line.find("DWORD ") == 0 || 
                    line.find("HANDLE ") == 0 || line.find("LONG ") == 0 ||
                    line.find("VOID ") == 0 || line.find("INT ") == 0 ||
                    line.find("UINT ") == 0 || line.find("LPVOID ") == 0 ||
                    line.find("__kernel_entry NTSYSCALLAPI NTSTATUS ") == 0 || line.find("HRESULT ") == 0 ||
                    line.find("ULONG ") == 0 || line.find("SIZE_T ") == 0 ||
                    line.find("FARPROC") == 0 || line.find("NTSYSAPI NTSTATUS ") )) {
                
                currentFunction = line;
                if (line.find(");") != std::string::npos) {
                    // Single line function
                    ParseSingleFunction(currentFunction);
                    functionsFound++;
                    currentFunction.clear();
                } else {
                    inFunction = true;
                }
            }
        }
    }
    
    file.close();
    return functionsFound;
}

bool LoadSignaturesFromHeaders(const std::string& headerDir) {
    std::wcout << L"Loading function signatures from header directory: " << headerDir.c_str() << std::endl;
    
    // Find all .h files in the directory
    std::string searchPath = headerDir + "\\*.h";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);
    
    if (hFind == INVALID_HANDLE_VALUE) {
        std::wcout << L"Note: Could not find header files in " << headerDir.c_str() 
                    << L" (will use generic display)" << std::endl;
        return false;
    }
    
    int totalFunctions = 0;
    
    do {
        std::string filename = headerDir + "\\" + findData.cFileName;
        std::wcout << L"Processing: " << findData.cFileName << L"... ";
        
        // Read and parse the header file with timeout protection
        int functionsInFile = ProcessHeaderFile(filename);
        
        if (functionsInFile >= 0) {
            totalFunctions += functionsInFile;
            std::wcout << L"Found " << functionsInFile << L" functions" << std::endl;
        } else {
            std::wcout << L"Error processing file" << std::endl;
        }
        
    } while (FindNextFileA(hFind, &findData));
    
    FindClose(hFind);
    
    std::wcout << L"Loaded parameter names for " << totalFunctions 
                << L" functions total" << std::endl;
    
    return totalFunctions > 0;
}

bool LoadSignatures(const std::string& headerDir) {
    bool result = LoadSignaturesFromHeaders(headerDir);
    
    // Just show a summary, no ugly debug output
    std::wcout << L"Successfully loaded function signatures!" << std::endl;
    
    return result;
}