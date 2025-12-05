#include "DynamicArray.h"
#include <iostream>


using namespace teaching;

int main() {
  try {
    std::cout << "=== Version 2: Pedagogic Best Practices ===\n";

    // 1. Initializer List
    DynamicArray arr = {10, 20, 30};
    std::cout << "Initialized: " << arr << "\n";

    // 2. Push Back
    arr.push_back(40);
    std::cout << "After push:  " << arr << "\n";

    // 3. Access via []
    std::cout << "Element at 1: " << arr[1] << "\n";
    arr[1] = 99;
    std::cout << "Modified at 1: " << arr << "\n";

    // 4. Exception Handling
    std::cout << "Attempting out of bounds access...\n";
    // arr[100] = 0; // Uncomment to test exception

  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << "\n";
  }

  return 0;
}
