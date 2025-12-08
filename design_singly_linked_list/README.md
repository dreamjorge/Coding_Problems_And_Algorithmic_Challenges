# Design Singly Linked List

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)

This directory contains the solution for the **Design Singly Linked List** problem, implemented across 5 architectural levels.

## Implementations

### [`01_student_intro`](01_student_intro/main.cpp)
*   **Goal:** Basic correctness for interviews.
*   **Features:** `struct Node`, `LinkedList` class, Manual `new`/`delete`.
*   **Compliance:** Strict adherence to `PROBLEM.md` (e.g., `get(i)` returns -1).

### [`02_pedagogic_oop`](02_pedagogic_oop)
*   **Goal:** Teaching C++ Best Practices.
*   **Features:** Rule of Three (Destructor, Copy Constructor, Assignment), `const` correctness, Separated Interface (`.h`) and Implementation (`.cpp`).

### [`03_industry_std`](03_industry_std)
*   **Goal:** Production-ready library container.
*   **Features:** `template <typename T>`, `Iterator` support (`begin`/`end`), Rule of Five (Move Semantics), Header-only (`.hpp`).

### [`04_embedded_fixed`](04_embedded_fixed)
*   **Goal:** No-Heap / Real-Time Systems.
*   **Features:** `StaticLinkedList<T, Capacity>`, Node pool in `std::array`, Index-based linking (`int16_t` indices).

### [`05_concurrent_safe`](05_concurrent_safe)
*   **Goal:** Thread Safety.
*   **Features:** `ThreadSafeLinkedList` wrapper using `std::shared_mutex` for Multiple Readers / Single Writer locking.

## Build & Run

```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```
