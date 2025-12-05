# Dynamic Array Evolution Project

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)

This repository demonstrates the evolution of a dynamic array implementation in C++, showcasing the progression from a basic student-level implementation to a robust, industry-standard container. It is structured into three distinct versions, each serving a specific educational and practical purpose.

## Project Structure

The project is divided into three isolated versions:

### 1. `v1_student` (The Basics)
*   **Goal:** To understand the fundamental concepts of dynamic memory allocation, pointers, and manual resource management.
*   **Key Concepts:** `new`, `delete`, Rule of Three, raw pointers.
*   **Implementation:** Single file (`main.cpp`) with console logging to visualize memory operations.

### 2. `v2_pedagogic` (Best Practices)
*   **Goal:** To introduce software engineering best practices, encapsulation, and code organization.
*   **Key Concepts:** Separation of interface (`.h`) and implementation (`.cpp`), Namespaces, Const Correctness, Operator Overloading, Initializer Lists.
*   **Implementation:** `DynamicArray` class within the `teaching` namespace.

### 3. `v3_industry` (Production Ready)
*   **Goal:** To create a generic, highly optimized, and robust container suitable for real-world use.
*   **Key Concepts:** Templates, Move Semantics (Rule of Five), Exception Safety (Strong Guarantee), Iterators, Header-only library design.
*   **Implementation:** `DynamicArray<T>` template class within the `industry` namespace.

## Getting Started

### Prerequisites
*   C++ Compiler supporting C++17 (GCC, Clang, MSVC)
*   CMake (3.10 or higher)

### Building the Project

1.  Clone the repository:
    ```bash
    git clone https://github.com/yourusername/dynamic-array-evolution.git
    cd dynamic-array-evolution
    ```

2.  Create a build directory:
    ```bash
    mkdir build && cd build
    ```

3.  Generate build files with CMake:
    ```bash
    cmake ..
    ```

4.  Build all versions:
    ```bash
    cmake --build .
    ```

### Running the Examples

After building, you will have three executables in the `bin` directory (or `Debug`/`Release` on Windows):

*   `./v1_student`
*   `./v2_pedagogic`
*   `./v3_industry`

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
