cmake_minimum_required(VERSION 3.10)

project(SinglyLinkedListProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --- 01. Student Intro ---
add_executable(ll_01_student 01_student_intro/cpp/main.cpp)

# --- 02. Pedagogic OOP ---
add_executable(ll_02_pedagogic 
    02_pedagogic_oop/cpp/main.cpp
    02_pedagogic_oop/cpp/LinkedList.cpp
)
target_include_directories(ll_02_pedagogic PRIVATE 02_pedagogic_oop/cpp)

# --- 03. Industry Std ---
add_executable(ll_03_industry 03_industry_std/cpp/main.cpp)
target_include_directories(ll_03_industry PRIVATE 03_industry_std/cpp)

# --- 04. Embedded Fixed ---
add_executable(ll_04_embedded 04_embedded_fixed/cpp/main.cpp)
target_include_directories(ll_04_embedded PRIVATE 04_embedded_fixed/cpp)

# --- 05. Concurrent Safe ---
add_executable(ll_05_concurrent 05_concurrent_safe/cpp/main.cpp)
target_include_directories(ll_05_concurrent PRIVATE 05_concurrent_safe/cpp)

# --- Testing ---
enable_testing()
add_test(NAME TestLinkedList01 COMMAND ll_01_student)
add_test(NAME TestLinkedList02 COMMAND ll_02_pedagogic)
add_test(NAME TestLinkedList03 COMMAND ll_03_industry)
add_test(NAME TestLinkedList04 COMMAND ll_04_embedded)
add_test(NAME TestLinkedList05 COMMAND ll_05_concurrent)
