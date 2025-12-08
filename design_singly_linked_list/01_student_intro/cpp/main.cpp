#include <iostream>
#include <vector>

// ============================================================================
// 01: STUDENT / INTERVIEW
// Goal: Basic implementation using raw pointers.
// - Supports: Head/Tail insertion, removal by index, get by index.
// - Focus: Pointer manipulation logic.
// ============================================================================

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
  Node *head;
  Node *tail;
  int size;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  // Return the value of the ith node (0-indexed). If index out of bounds,
  // return -1.
  int get(int index) {
    if (index < 0 || index >= size)
      return -1;

    Node *curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->val;
  }

  // Insert a node with val at the head of the list.
  void insertHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (size == 0) {
      tail = newNode;
    }
    size++;
  }

  // Insert a node with val at the tail of the list.
  void insertTail(int val) {
    Node *newNode = new Node(val);
    if (size == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  // Remove the ith node (0-indexed).
  // Return false if invalid index, otherwise true.
  bool remove(int index) {
    if (index < 0 || index >= size)
      return false;

    if (index == 0) {
      Node *temp = head;
      head = head->next;
      if (size == 1) {
        tail = nullptr;
      }
      delete temp;
    } else {
      Node *prev = head;
      for (int i = 0; i < index - 1; ++i) {
        prev = prev->next;
      }
      Node *toDelete = prev->next;
      prev->next = toDelete->next;

      // If we deleted the tail, update tail
      if (index == size - 1) {
        tail = prev;
      }
      delete toDelete;
    }
    size--;
    return true;
  }

  // Return array of all values
  std::vector<int> getValues() {
    std::vector<int> res;
    Node *curr = head;
    while (curr) {
      res.push_back(curr->val);
      curr = curr->next;
    }
    return res;
  }
};

int main() {
  std::cout << "=== 01 (Student Intro) ===\n";

  // Example 1 Logic
  LinkedList list;
  std::cout << "insertHead(1)\n";
  list.insertHead(1);

  std::cout << "insertTail(2)\n";
  list.insertTail(2);

  std::cout << "insertHead(0)\n";
  list.insertHead(0);

  std::cout << "Values: [ ";
  for (int v : list.getValues())
    std::cout << v << " ";
  std::cout << "]\n";

  std::cout << "remove(1)\n";
  list.remove(1); // Removes element at index 1 (which is '1')

  std::vector<int> vals = list.getValues();
  std::cout << "Values: [ ";
  for (int v : vals)
    std::cout << v << " ";
  std::cout << "]\n"; // Expected: [0, 2]

  // Example 2 Logic
  LinkedList list2;
  list2.insertHead(1);
  list2.insertHead(2);
  std::cout << "get(5): " << list2.get(5) << "\n"; // Expected: -1

  return 0;
}
