cmake_minimum_required(VERSION 3.10)

# Project name
project(DynamicArrayProject)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --- Version 1: Student Learning ---
# Simple, single-file implementation for understanding basics
add_executable(01_student_intro 01_student_intro/main.cpp)

# --- Version 2: Pedagogic Improvement ---
# Separated interface/implementation, namespaces, const-correctness
add_executable(02_pedagogic_oop 
    02_pedagogic_oop/main.cpp 
    02_pedagogic_oop/DynamicArray.cpp
)
target_include_directories(02_pedagogic_oop PRIVATE 02_pedagogic_oop)

# --- Version 3: Real-World Industry ---
# Templates, Move Semantics, Iterators, Header-only (mostly)
add_executable(03_industry_std 03_industry_std/main.cpp)
target_include_directories(03_industry_std PRIVATE 03_industry_std)

# --- Version 4: Embedded / Low-Latency ---
# No Heap, Fixed Capacity, Error Codes
add_executable(04_embedded_fixed 04_embedded_fixed/main.cpp)
target_include_directories(04_embedded_fixed PRIVATE 04_embedded_fixed)

# --- Version 5: Concurrent / Thread-Safe ---
# Mutex protection, Shared Locks
add_executable(05_concurrent_safe 05_concurrent_safe/main.cpp)
target_include_directories(05_concurrent_safe PRIVATE 05_concurrent_safe)

# --- Testing ---
enable_testing()
add_test(NAME TestResult01 COMMAND 01_student_intro)
add_test(NAME TestResult02 COMMAND 02_pedagogic_oop)
add_test(NAME TestResult03 COMMAND 03_industry_std)
add_test(NAME TestResult04 COMMAND 04_embedded_fixed)
add_test(NAME TestResult05 COMMAND 05_concurrent_safe)
