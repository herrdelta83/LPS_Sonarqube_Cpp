## LPS

## What does it does?

This small C++ project provides a utility to check for palindromes. The implementation lives in `include/Palindrome.h`, `src/Palindrome.cpp` and the program entrypoint is `src/main.cpp`.

## How to compile it?

You can compile the project with `g++` (MinGW on Windows or any modern GCC on Linux/macOS):

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o lps.exe
```

Run the program:

```bash
./lps.exe    # or .\\lps.exe on Windows PowerShell/CMD
```

If you prefer MSVC (Visual Studio) on Windows, use the Developer Command Prompt:

```powershell
# from project root
cl /EHsc /I include src\\*.cpp /Fe:lps.exe
```

Alternatively, create a simple `CMakeLists.txt` and build with CMake if you want an out-of-source build.

## Screenshots from SonarQube scan

![SonarQube - Overview](docs/sonarqube/sonarqube-overview.png)
