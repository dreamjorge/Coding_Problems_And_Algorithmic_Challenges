#include "StaticLinkedList.hpp"
#include <iostream>

int main() {
  std::cout << "=== 04 (Embedded Fixed) ===\n";

  // Create a list with capacity 5
  embedded::StaticLinkedList<int, 5> list;

  for (int i = 0; i < 5; ++i) {
    if (!list.insertTail(i * 10)) {
      std::cout << "Failed to insert " << i * 10 << "\n";
    }
  }
  list.print();

  std::cout << "Insert 50 (Should FAIL - Full)\n";
  if (!list.insertTail(50)) {
    std::cout << "--> correctly failed (OOM).\n";
  }

  std::cout << "Remove index 0 (0)\n";
  list.remove(0);
  list.print();

  std::cout << "Insert 60 (Should succeed now)\n";
  list.insertHead(60);
  list.print();

  return 0;
}
