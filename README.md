# ArgusTrace API Tracer

## Overview

ArgusTrace is a Windows API tracing framework that supports both **breakpoint-based tracing** and **dynamic binary instrumentation**. It is primarily intended for reverse engineering, malware analysis, and behavioral observation of Windows executables.

Version: **1.0.0**  
Status: **Stable (breakpoint-based tracing)**, **Experimental (DynamoRIO instrumentation)**

---

## Features

- Breakpoint-based API hooking with argument logging
- Multi-DLL support defined via `argus.config`
- Child process tracing with adjustable trace depth
- Configurable delay after process creation for ScyllaHide compatibility
- Non-hardcoded paths (e.g., `dll_headers` path provided via argument)
- Support for attaching to running processes via PID
- Optional file-based logging
- Interactive mode for manual control
- Clear executable naming and icons included
- Organized build structure

---

## Tracing Methods

### Breakpoint-Based Tracing (Stable)

- Hooks functions by setting breakpoints at known API entry points
- Supports multiple Windows DLLs (e.g., kernel32.dll, ntdll.dll, others)
- API functions are defined via header files in `dll_headers`, controlled by `argus.config`
- Child process creation is monitored and traced
- Modules are enumerated and breakpoints set after the entry point is reached
- All previously unused or broken command-line parameters have been removed

### DynamoRIO Instrumentation (Experimental)

- Utilizes [DynamoRIO](https://dynamorio.org/) to inject tracing logic into the target process
- Now avoids tracing itself during runtime
- Can be built optionally if desired

---

## Build Instructions

### Prerequisites

- Visual Studio 2022 (with C++ development tools)
- Latest Windows SDK
- DynamoRIO (optional, only for DynamoRIO tracer)

### Building with Batch Script

1. Open `CMD`
2. Navigate to the root of the project directory
3. Run:

```bat
build_tracer.bat
```
This will compile both x86 and x64 versions and place the resulting executables in the `build/` directory.

---

## Usage

```sh
tracer32.exe | tracer64.exe [OPTIONS] <victim.exe>
```

## Command-Line Options

| Option            | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `-c`, `--choice`  | Select tracing method (`bp` for breakpoint, `dr` for DynamoRIO)            |
| `-d`, `--dll-headers` | Path to directory containing API header files                         |
| `-f`, `--file`    | Output trace logs to specified file                                        |
| `-p`, `--pid`     | Attach to a running process by PID                                         |
| `-s`, `--sleep`   | Sleep after process creation (useful for ScyllaHide)                       |
| `--trace-level`   | Set child process tracing depth: `-1` disables, `0` is unlimited, `1+` for depth |
| `-i`, `--interactive` | Enable interactive console mode                                       |

> **Note**: `argus.config` must be present inside the specified `dll_headers` directory when using breakpoint-based tracing. It defines the list of DLLs and functions to trace.

---

## Directory Structure

/build - Output binaries (x86 and x64)
/dll_headers - Header files and argus.config (used for breakpoint tracing)
/tracer - Core source files
build_tracer.bat - Batch script for building the project


---

## Current Limitations

- No stealth or anti-debugging mechanisms implemented yet  
- DynamoRIO-based instrumentation is still experimental  
- Output logging is minimal and subject to future redesign  
- No GUI or visualization interface (CLI only)  

---

## Development Roadmap

Planned improvements and features:

- Stealth and anti-detection capabilities  
- JSON or database-backed output formats  
- Advanced trace filtering options  
- System call-level tracing  
---

## Contributing

Contributions are encouraged. To contribute:

1. Fork the repository  
2. Create a new branch:

   ```bash
   git checkout -b feature-branch

## Contributing (continued)

4. Commit your changes  
5. Push your branch and open a pull request  

Suggestions and issues can also be submitted through the GitHub issue tracker.

---

## Related Projects

- **windows_function_scraper**: Generates Windows API function headers for use with ArgusTrace.  
- **DynamoRIO**: Dynamic instrumentation framework used in alternative tracing mode.  

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for full terms.

