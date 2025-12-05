# Design Dynamic Array (Resizable Array)

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)

This directory contains the solution for the **Design Dynamic Array** problem. It implements a resizable array (similar to `std::vector` in C++ or `ArrayList` in Java).

For the detailed project philosophy (Student vs. Pedagogic vs. Industry versions), please refer to the [Root README](../README.md).

## Problem Description
See [PROBLEM.md](PROBLEM.md) for the full requirements and examples.

## Implementations

### [`01_student_intro`](01_student_intro/main.cpp)
*   Strict compliance with the [PROBLEM.md](PROBLEM.md) requirements.
*   Implements `pushback`, `popback`, `set`, `get`, `resize`.
*   Uses raw pointers and manual `new`/`delete` for learning purposes.

### [`02_pedagogic_oop`](02_pedagogic_oop)
*   Implements `std::vector`-like interface (`push_back`, `pop_back`, `operator[]`).
*   Demonstrates separation of interface (`.h`) and implementation (`.cpp`).
*   Uses `namespace teaching`.

### [`03_industry_std`](03_industry_std)
*   Production-grade implementation using Templates (`<T>`) and Move Semantics.
*   Strong Exception Guarantee.
*   Uses `namespace industry`.

### [`04_embedded_fixed`](04_embedded_fixed)
*   **Target:** Embedded Systems / Real-time.
*   **Constraint:** No Heap Allocation (`new`/`delete` forbidden).
*   **Strategy:** Wrapper around `std::array` (Stack/Static memory).
*   **Safety:** Returns `false` on overflow instead of resizing.

### [`05_concurrent_safe`](05_concurrent_safe)
*   **Target:** Multi-threaded Backend Systems.
*   **Constraint:** Thread Safety.
*   **Strategy:** Uses `std::shared_mutex` (One Writer, Multiple Readers).
*   **Features:** Thread-safe `push_back`, `get`, and snapshotting.

## Quick Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```
