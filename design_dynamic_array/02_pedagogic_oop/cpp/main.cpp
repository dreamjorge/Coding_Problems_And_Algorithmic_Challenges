#include "DynamicArray.h"
#include <iostream>

int main() {
  std::cout << "=== 02 (Pedagogic OOP) ===\n";

  // 1. Create a Dynamic Array
  teaching::DynamicArray arr(2);
  arr.push_back(10);
  arr.push_back(20);
  arr.push_back(30);

  // 2. Print using overloaded <<
  std::cout << "Initial Array: " << arr << "\n";

  arr.push_back(40);
  std::cout << "After push:  " << arr << "\n";

  // 3. Access via []
  std::cout << "Element at 1: " << arr[1] << "\n";
  arr[1] = 99;
  std::cout << "Modified at 1: " << arr << "\n";

  // 4. Exception Handling
  std::cout << "Attempting out of bounds access...\n";
  try {
    // arr[100] = 0; // Uncomment to test exception
    int val = arr[100];
    std::cout << "Val: " << val << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << "\n";
  }

  return 0;
}
