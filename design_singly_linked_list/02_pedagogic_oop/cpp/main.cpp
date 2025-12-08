#include "LinkedList.h"
#include <iostream>

int main() {
  std::cout << "=== 02 (Pedagogic OOP) ===\n";

  teaching::LinkedList list;
  list.insertHead(10);
  list.insertTail(20);
  list.insertTail(30);

  std::cout << "Values: ";
  for (int v : list.getValues())
    std::cout << v << " ";
  std::cout << "\n";

  // Copy Constructor Test
  {
    teaching::LinkedList copy = list;
    copy.insertTail(999);
    std::cout << "Copy should have 999: ";
    for (int v : copy.getValues())
      std::cout << v << " ";
    std::cout << "\n";
  }

  std::cout << "Original should NOT have 999: ";
  for (int v : list.getValues())
    std::cout << v << " ";
  std::cout << "\n";

  return 0;
}
