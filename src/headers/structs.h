// breakpoint information
struct Breakpoint {
    PVOID address;
    BYTE originalByte;
    std::string functionName;
    bool isActive;
    bool isSet;
};

// API function configuration
struct ApiFunction {
    std::string name;
    std::string module;
    DWORD paramCount;
};