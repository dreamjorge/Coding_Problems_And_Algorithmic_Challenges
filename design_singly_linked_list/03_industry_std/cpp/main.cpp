#include "LinkedList.hpp"
#include <iostream>
#include <string>

// Simple struct to test Emplace/Move
struct User {
  std::string name;
  int id;

  User(std::string n, int i) : name(std::move(n)), id(i) {}
}; // Added missing semicolon/closing brace if needed, but struct ends here.

int main() {
  std::cout << "=== 03 (Industry Std) ===\n";

  // 1. Int List
  industry::LinkedList<int> list;
  list.insertTail(1);
  list.insertTail(2);
  list.insertTail(3);

  std::cout << "Ints: ";
  for (int x : list) { // Iterator test
    std::cout << x << " ";
  }
  std::cout << "\n";

  // 2. String List (Move Semantics)
  industry::LinkedList<std::string> strList;
  strList.insertTail("World");
  strList.insertHead("Hello"); // uses insertHead(T&&)

  std::cout << "Strings: ";
  for (const auto &s : strList) {
    std::cout << s << " ";
  }
  std::cout << "\n";

  // 3. User List
  industry::LinkedList<User> userList;
  userList.insertTail(User("Alice", 1));
  userList.insertTail(User("Bob", 2));

  // Test get()
  try {
    User u = userList.get(0);
    std::cout << "User 0: " << u.name << "\n";
    userList.get(100); // Should throw
  } catch (const std::exception &e) {
    std::cout << "Caught expected error: " << e.what() << "\n";
  }

  return 0;
}
