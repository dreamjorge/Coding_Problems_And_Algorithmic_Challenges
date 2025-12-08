# Coding Problems Collection

![License](https://img.shields.io/badge/license-MIT-blue.svg)

This repository contains solutions to various coding problems and algorithmic challenges, implemented with a focus on educational value and industry best practices.

## Project Philosophy

Current coding interview resources often present a single "optimal" solution that is either too complex for beginners or lacks real-world software engineering depth. This repository solves that by providing **five distinct versions** for every problem, simulating the career growth of a software engineer:

### 1. `01_student_intro` (The Basics)
*   **Target Audience:** First-time learners, Whiteboard Interviews.
*   **Goal:** Minimal syntax, focus on the raw algorithm, manual memory management.

### 2. `02_pedagogic_oop` (Best Practices)
*   **Target Audience:** Software Engineering Interviews, Code Reviews.
*   **Goal:** Clean code, modularity, and correctness.

### 3. `03_industry_std` (Production Ready)
*   **Target Audience:** Senior Engineers, High-Performance Systems.
*   **Goal:** Optimization, generic programming, and standard compliance.

### 4. `04_embedded_fixed` (Systems Programming)
*   **Target Audience:** Embedded/Real-Time Engineers (IoT, Automotive).
*   **Goal:** Deterministic memory, no heap, fixed capacity.

### 5. `05_concurrent_safe` (Backend Infrastructure)
*   **Target Audience:** Platform Engineers, High-Frequency Trading.
*   **Goal:** Thread safety, atomic operations, locking strategies.

## Solved Problems

| Problem | Description | Languages |
| :--- | :--- | :--- |
| [Design Dynamic Array](./design_dynamic_array) | Implementation of a resizable array (Vector/ArrayList) with multiple complexity levels. | C++17 |

## Detailed Comparison Guide

| Feature | `01_student` | `02_pedagogic` | `03_industry` | `04_embedded` | `05_concurrent` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Complexity** | Low | Medium | High | Low | Medium |
| **Allocation** | Manual Heap | Manual Heap | Custom/Heap | **Stack/Static** | Heap |
| **Safety** | Low | High | Exception Safe | **No Exceptions** | **Thread Safe** |
| **Reusability** | None | Low | High | High | High |
| **Interview** | Algorithms | OOD | Senior / Systems | Embedded | Scaling / Backend |

## References & Further Reading

To deepen your understanding of the concepts used in these versions, we recommend the following resources:

### 1. Algorithms & Basics (01_student)
*   **Book:** *Cracking the Coding Interview* by Gayle Laakmann McDowell.
*   **Book:** *Grokking Algorithms* by Aditya Bhargava.
*   **Web:** [GeeksforGeeks Data Structures](https://www.geeksforgeeks.org/data-structures/)

### 2. Software Engineering (02_pedagogic)
*   **Book:** *Effective C++* by Scott Meyers (Essential for Rule of Three/Five).
*   **Book:** *Clean Code* by Robert C. Martin.
*   **Web:** [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

### 3. Advanced C++ (03_industry)
*   **Book:** *C++ Templates: The Complete Guide* by Vandevoorde et al.
*   **Book:** *C++ Move Semantics* by Nicolai M. Josuttis.
*   **Web:** [cppreference.com](https://en.cppreference.com/) - The bible for standard library types.

### 4. Systems & Embedded (04_embedded)
*   **Book:** *Real-Time C++* by Christopher Kormanyos.
*   **Book:** *Making Embedded Systems* by Elecia White.
*   **Web:** [Embedded Template Library (ETL)](https://www.etlcpp.com/)

### 5. Concurrency (05_concurrent)
*   **Book:** *C++ Concurrency in Action* by Anthony Williams.
*   **Concept:** [Readers-Writer Lock (Wikipedia)](https://en.wikipedia.org/wiki/Readers%E2%80%93writer_lock)

## Usage

You can run the provided scripts in the `scripts/` directory to build and run specific versions.

### Powershell Scripts
*   **Build All**:
    ```powershell
    ./scripts/build_all.ps1
    ```
*   **Run Specific Version**:
    ```powershell
    ./scripts/build_da_01.ps1  # Runs Dynamic Array Version 1
    ./scripts/build_ll_05.ps1  # Runs Linked List Version 5
    ```

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
