#ifndef LINKED_LIST_V2_H
#define LINKED_LIST_V2_H

#include <iostream>
#include <vector>

namespace teaching {

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int size_count;

public:
  // Constructor
  LinkedList();

  // Destructor (Rule of 3)
  ~LinkedList();

  // Copy Constructor (Rule of 3)
  LinkedList(const LinkedList &other);

  // Copy Assignment Operator (Rule of 3)
  LinkedList &operator=(const LinkedList &other);

  // Operations
  int get(int index) const;
  void insertHead(int val);
  void insertTail(int val);
  bool remove(int index);
  std::vector<int> getValues() const;

  int size() const;
};

} // namespace teaching

#endif // LINKED_LIST_V2_H
