# Design Dynamic Array (Resizable Array)

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)

This directory contains the solution for the **Design Dynamic Array** problem. It implements a resizable array (similar to `std::vector` in C++ or `ArrayList` in Java).

For the detailed project philosophy (Student vs. Pedagogic vs. Industry versions), please refer to the [Root README](../README.md).

## Problem Description
See [PROBLEM.md](PROBLEM.md) for the full requirements and examples.

## Implementations

### [`v1_student`](v1_student/main.cpp)
*   Strict compliance with the [PROBLEM.md](PROBLEM.md) requirements.
*   Implements `pushback`, `popback`, `set`, `get`, `resize`.
*   Uses raw pointers and manual `new`/`delete` for learning purposes.

### [`v2_pedagogic`](v2_pedagogic)
*   Implements `std::vector`-like interface (`push_back`, `pop_back`, `operator[]`).
*   Demonstrates separation of interface (`.h`) and implementation (`.cpp`).
*   Uses `namespace teaching`.

### [`v3_industry`](v3_industry)
*   Production-grade implementation using Templates (`<T>`) and Move Semantics.
*   Strong Exception Guarantee.
*   Uses `namespace industry`.

## Quick Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```
