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
add_executable(v1_student v1_student/main.cpp)

# --- Version 2: Pedagogic Improvement ---
# Separated interface/implementation, namespaces, const-correctness
add_executable(v2_pedagogic 
    v2_pedagogic/main.cpp 
    v2_pedagogic/DynamicArray.cpp
)
target_include_directories(v2_pedagogic PRIVATE v2_pedagogic)

# --- Version 3: Real-World Industry ---
# Templates, Move Semantics, Iterators, Header-only (mostly)
add_executable(v3_industry v3_industry/main.cpp)
target_include_directories(v3_industry PRIVATE v3_industry)

# --- Testing ---
enable_testing()
add_test(NAME TestV1 Command v1_student)
add_test(NAME TestV2 Command v2_pedagogic)
add_test(NAME TestV3 Command v3_industry)
