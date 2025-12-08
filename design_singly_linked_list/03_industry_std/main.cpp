#include "LinkedList.hpp"
#include <iostream>
#include <string>


// Simple struct to test Emplace/Move
struct User {
  std::string name;
  int id;

  User(std::string n, int i) : name(std::move(n)), id(i) {}

  // Disable copy to prove move works (though LinkedList implementation uses
  // copy for some ops, so we might need copy) Actually, industry::LinkedList
  // copy ctor USES T copy ctor. So T must be copyable for list usage.
};

int main() {
  std::cout << "=== Linked List v3 (Industry) ===\n";

  // 1. Integer List
  industry::LinkedList<int> list;
  list.insertTail(10);
  list.insertTail(20);
  list.insertHead(5);

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
