// g++ src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp -m64 -municode --static -o tracer64.exe
// g++ src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp -m32 -municode --static -o tracer32.exe

#include <stdio.h>
#include <windows.h>

int main() {
    printf("Starting victim program...\n");
    Sleep(20000);
    
    // Create a file
    HANDLE hFile = CreateFileA(
        "test_output.txt",          // File name
        GENERIC_WRITE,              // Desired access
        0,                          // Share mode
        NULL,                       // Security attributes
        CREATE_ALWAYS,              // Creation disposition
        FILE_ATTRIBUTE_NORMAL,      // File attributes
        NULL                        // Template file
    );
    
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("CreateFile failed with error: %lu\n", GetLastError());
        return 1;
    }
    
    printf("File created successfully\n");
    
    // Write to the file
    const char* data = "Hello from victim program!\nThis is a test file.\n";
    DWORD bytesWritten = 0;
    
    BOOL result = WriteFile(
        hFile,                      // File handle
        data,                       // Data to write
        (DWORD)strlen(data),        // Number of bytes to write
        &bytesWritten,              // Bytes written
        NULL                        // Overlapped
    );
    
    if (result) {
        printf("Successfully wrote %lu bytes to file\n", bytesWritten);
    } else {
        printf("WriteFile failed with error: %lu\n", GetLastError());
    }
    
    // Close the file
    CloseHandle(hFile);
    printf("File closed\n");
    
    printf("Victim program finished\n");
    return 0;
}