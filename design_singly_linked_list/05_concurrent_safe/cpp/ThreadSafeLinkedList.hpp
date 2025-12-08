#ifndef LINKED_LIST_05_CONCURRENT_SAFE_HPP
#define LINKED_LIST_05_CONCURRENT_SAFE_HPP

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>

/**
 * @brief Thread-Safe Singly Linked List.
 *
 * Uses coarse-grained locking with std::shared_mutex.
 * - Readers (get, size, getValues) use shared_lock.
 * - Writers (insert, remove) use unique_lock.
 */
namespace concurrent {

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

class ThreadSafeLinkedList {
private:
  Node *head;
  Node *tail;
  int size_count;
  mutable std::shared_mutex m_mutex; // Protects all member vars

public:
  ThreadSafeLinkedList() : head(nullptr), tail(nullptr), size_count(0) {}

  ~ThreadSafeLinkedList() {
    // We assume no threads accessing during destruction
    Node *curr = head;
    while (curr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }

  /**
   * @brief Insert at head (Thread-Safe Writer).
   * @param val Value to insert.
   */
  void insertHead(int val) {
    std::unique_lock<std::shared_mutex> lock(m_mutex); // Writer Lock
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (!tail)
      tail = newNode;
    size_count++;
  }

  void insertTail(int val) {
    std::unique_lock<std::shared_mutex> lock(m_mutex); // Writer Lock
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size_count++;
  }

  bool remove(int index) {
    std::unique_lock<std::shared_mutex> lock(m_mutex); // Writer Lock
    if (index < 0 || index >= size_count)
      return false;

    Node *toDelete = nullptr;
    if (index == 0) {
      toDelete = head;
      head = head->next;
      if (size_count == 1)
        tail = nullptr;
    } else {
      Node *prev = head;
      for (int i = 0; i < index - 1; ++i)
        prev = prev->next;

      toDelete = prev->next;
      prev->next = toDelete->next;
      if (index == size_count - 1)
        tail = prev;
    }
    delete toDelete;
    size_count--;
    return true;
  }

  int get(int index) const {
    std::shared_lock<std::shared_mutex> lock(m_mutex); // Reader Lock
    if (index < 0 || index >= size_count)
      return -1;

    Node *curr = head;
    for (int i = 0; i < index; ++i)
      curr = curr->next;
    return curr->val;
  }

  // Snapshot: Returns a thread-safe copy of values
  std::vector<int> getValues() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex); // Reader Lock
    std::vector<int> res;
    res.reserve(size_count);
    Node *curr = head;
    while (curr) {
      res.push_back(curr->val);
      curr = curr->next;
    }
    return res; // RVO (Return Value Optimization)
  }

  int size() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    return size_count;
  }
};

} // namespace concurrent

#endif // LINKED_LIST_05_CONCURRENT_SAFE_HPP
