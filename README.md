# Project README

## Overview
This project is a C/C++ program that provides various functionalities related to fixed-point numbers. The main functionality includes parsing, converting, and manipulating fixed-point values in different precision levels (16-bit, 32-bit, 64-bit). It uses custom header files for each precision level and includes Makefiles for building the project on Linux, Windows, Wine, and WebAssembly.

## Features
- Parsing of fixed-point numbers from strings.
- Conversion of fixed-point numbers to double precision floating point values.
- Arithmetic operations (addition, subtraction, multiplication, division) on fixed-point numbers.
- Support for different precision levels: 16-bit, 32-bit, and 64-bit.

## Project Structure
- `src/`
  - `Main.c`          # Entry point of the program
  - `Fixed16.h`       # Header file for 16-bit fixed-point operations
  - `Fixed32.h`       # Header file for 32-bit fixed-point operations
  - `Fixed64.h`       # Header file for 64-bit fixed-point operations
- `Makefile.linux`    # Linux Build configuration
- `Makefile.windows`  # Windows Build configuration
- `Makefile.wine`     # Wine Build configuration
- `Makefile.web`      # Emscripten Build configuration
- `README.md`         # This file

## Build & Run
To build and run the project, follow these steps:

### Linux
1. Open a terminal.
2. Navigate to the project directory.
3. Build the project using:
   ```sh
   make -f Makefile.linux all
   ```
4. Execute the program:
   ```sh
   ./build/Main
   ```

### Windows
1. Open a Command Prompt or PowerShell.
2. Navigate to the project directory.
3. Build the project using:
   ```sh
   mingw32-make -f Makefile.windows all
   ```
4. Execute the program:
   ```sh
   build\Main.exe
   ```

### Wine
1. Open a terminal on Linux.
2. Navigate to the project directory.
3. Build the project using:
   ```sh
   make -f Makefile.wine all
   ```
4. Execute the program:
   ```sh
   wine build/Main.exe
   ```

### WebAssembly (Emscripten)
1. Ensure Emscripten is installed and configured.
2. Open a terminal or Command Prompt.
3. Navigate to the project directory.
4. Build the project using:
   ```sh
   emmake make -f Makefile.web all
   ```
5. Run the WebAssembly file using `wasmtime`:
   ```sh
   wasmtime build/Main.wasm
   ```

These steps will allow you to build and run the project on different platforms, providing a clear understanding of how to interact with and utilize the fixed-point number functionalities in the program.