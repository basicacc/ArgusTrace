# WraithTrace API Tracer

## Current Status: Pre-Alpha
This tool is in early development. Most components are experimental and subject to change.

## Tracing Methods
WraithTrace currently implements two tracing techniques:

1. **Breakpoint-based Tracing**
   - Hooks Windows API functions via DLL breakpoints
   - Captures function calls with arguments
   - Requires `dll_headers` directory containing Windows API definitions
   - Compatible with [windows_function_scraper](https://github.com/basicacc/windows_functions_scraper) for header generation

2. **DynamoRIO Instrumentation**
   - Dynamic binary instrumentation approach
   - Provides alternative tracing methodology

*Note: These methods are independent - the tool functions with either one implemented.*

# WraithTrace Build Guide

## Prerequisites
- **Visual Studio 2022** (with C++ tools)
- **Windows SDK** (latest version recommended)
- **DynamoRIO** (if building DynamoRIO tracer)

## Quick Build (Batch Method)
1. Open **CMD**
2. Navigate to project directory
3. Run:
   ```bat
   build_tracer.bat

## Usage
```sh
WraithTrace.exe [-c CHOICE] [-d dll_headers] <victim.exe>
```

## Important Note
> Several command line parameters are currently non-functional and reserved for future implementation.

## Requirements
**For breakpoint-based tracing:**
- `dll_headers` directory must be present in executable folder
- Windows API header files (can be generated using [windows_function_scraper](https://github.com/basicacc/windows_functions_scraper))

## Current Limitations
- 🚫 No stealth capabilities (*planned for future versions*)
- 🚫 Child process tracing not yet implemented
- 🚫 Limited method configuration options
- 🚫 Partial command line argument support

## Development Roadmap
Planned improvements include:
- Enhanced tracing method selection
- Stealth/anti-detection features
- Child process monitoring
- Complete command line interface
- Additional tracing techniques

## Contributing
This project is in active development. Contributions and suggestions are welcome.
