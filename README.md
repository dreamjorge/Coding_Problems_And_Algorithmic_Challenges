# Coding Problems Collection

![License](https://img.shields.io/badge/license-MIT-blue.svg)

This repository contains solutions to various coding problems and algorithmic challenges, implemented with a focus on educational value and industry best practices.

## Project Philosophy

Current coding interview resources often present a single "optimal" solution that is either too complex for beginners or lacks real-world software engineering depth. This repository solves that by providing **three distinct versions** for every problem:

### 1. `v1_student` (The Basics)
*   **Target Audience:** First-time learners, Whiteboard Interviews.
*   **Goal:** Minimal syntax, focus on the raw algorithm, manual memory management.
*   **Style:** Single file, simple types (e.g., `int`), "LeetCode" style.

### 2. `v2_pedagogic` (Best Practices)
*   **Target Audience:** Software Engineering Interviews, Code Reviews.
*   **Goal:** Clean code, modularity, and correctness.
*   **Style:** Separated header/implementation, `const` correctness, namespaces, proper error handling.

### 3. `v3_industry` (Production Ready)
*   **Target Audience:** Senior Engineers, High-Performance Systems.
*   **Goal:** Optimization, generic programming, and standard compliance.
*   **Style:** Templates (`T`), Move Semantics, Iterators, Custom Allocators, Rule of Five.

## Solved Problems

| Problem | Description | Languages |
| :--- | :--- | :--- |
| [Design Dynamic Array](./design_dynamic_array) | Implementation of a resizable array (Vector/ArrayList) with multiple complexity levels. | C++17 |

## Detailed Comparison Guide

| Feature | `v1_student` | `v2_pedagogic` | `v3_industry` |
| :--- | :--- | :--- | :--- |
| **Complexity** | Low | Medium | High |
| **Performance** | Basic | Standard | Optimized |
| **Safety** | Low (Raw Pointers) | High (Encapsulated) | High (Exception Safe) |
| **Reusability** | None (Hardcoded types) | Low (Specific types) | High (Templates) |
| **Interview Use** | Algorithmic rounds | System Design / cleanup | Senior / Systems roles |

## Getting Started

### Prerequisites
*   C++ Compiler (GCC, Clang, MSVC) supporting C++17.
*   CMake (3.10+).

### Building a Problem
Each problem is a self-contained CMake project. To build the **Dynamic Array** solution, for example:

1.  Clone the repository:
    ```bash
    git clone https://github.com/dreamjorge/Coding_Problems_And_Algorithmic_Challenges.git
    cd Coding_Problems_And_Algorithmic_Challenges
    ```

2.  Navigate to the problem directory:
    ```bash
    cd design_dynamic_array
    ```

3.  Build using CMake:
    ```bash
    mkdir build && cd build
    cmake ..
    cmake --build .
    ```

4.  Run the versions:
    *   `./v1_student`
    *   `./v2_pedagogic`
    *   `./v3_industry`

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
