#ifndef LINKED_LIST_02_PEDAGOGIC_H
#define LINKED_LIST_02_PEDAGOGIC_H

#include <iostream>
#include <vector>

// ============================================================================
// 02: PEDAGOGIC IMPROVEMENT
// Goal: Encapsulated class with proper Rule of Three.
// ============================================================================

namespace teaching {

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

/**
 * @brief Encapsulated Singly Linked List.
 *
 * Implements Rule of Three to manage memory correctly (Destructor, Copy Ctor,
 * Copy Assignment).
 */
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
  // Copy Assignment Operator (Rule of Three)
  /**
   * @brief Copy Assignment Operator.
   * @param other List to copy from.
   * @return LinkedList& Reference to self.
   */
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

#endif // LINKED_LIST_02_PEDAGOGIC_H
