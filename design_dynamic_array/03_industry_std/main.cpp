#include "DynamicArray.hpp"
#include <iostream>
#include <string>
#include <vector>


using namespace industry;

// A helper class to demonstrate move semantics
class MovableString {
public:
  std::string str;

  // Default Constructor
  MovableString() : str("") { std::cout << "  [Default Construct]\n"; }

  MovableString(const char *s) : str(s) {
    std::cout << "  [Construct] " << str << "\n";
  }
  MovableString(const MovableString &other) : str(other.str) {
    std::cout << "  [Copy] " << str << "\n";
  }

  // Move Constructor
  MovableString(MovableString &&other) noexcept : str(std::move(other.str)) {
    std::cout << "  [Move] " << str << "\n";
  }

  // Copy Assignment
  MovableString &operator=(const MovableString &other) {
    if (this != &other) {
      str = other.str;
      std::cout << "  [Copy Assign] " << str << "\n";
    }
    return *this;
  }

  // Move Assignment
  MovableString &operator=(MovableString &&other) noexcept {
    if (this != &other) {
      str = std::move(other.str);
      std::cout << "  [Move Assign] " << str << "\n";
    }
    return *this;
  }

  ~MovableString() { /* std::cout << "  [Destruct]\n"; */ }
};

int main() {
  std::cout << "=== Version 3: Industry Standard ===\n";

  // 1. Template Support (int)
  std::cout << "\n--- Integer Array ---\n";
  DynamicArray<int> intArr = {1, 2, 3, 4, 5};
  for (int x : intArr) { // Range-based for loop (Iterators)
    std::cout << x << " ";
  }
  std::cout << "\n";

  // 2. Template Support (std::string) & Emplace
  std::cout << "\n--- String Array ---\n";
  DynamicArray<std::string> strArr;
  strArr.push_back("Hello");
  strArr.emplace_back("World"); // Construct in place
  for (const auto &s : strArr) {
    std::cout << s << " ";
  }
  std::cout << "\n";

  // 3. Move Semantics
  std::cout << "\n--- Move Semantics Test ---\n";
  DynamicArray<MovableString> moveArr;
  moveArr.push_back(MovableString("Item 1")); // Should move
  moveArr.push_back(MovableString("Item 2")); // Should move

  std::cout << "Triggering Resize...\n";
  moveArr.push_back(
      MovableString("Item 3")); // Resize should move existing elements

  return 0;
}
