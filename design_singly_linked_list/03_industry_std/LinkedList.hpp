#ifndef LINKED_LIST_03_INDUSTRY_STD_HPP
#define LINKED_LIST_03_INDUSTRY_STD_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>

namespace industry {

template <typename T> struct Node {
  T val;
  Node *next;

  template <typename... Args>
  Node(Args &&...args) : val(std::forward<Args>(args)...), next(nullptr) {}
};

/**
 * @brief Industry standard Singly Linked List.
 *
 * Features:
 * - Templates for generic type support.
 * - Iterators (begin/end) for range-based loops.
 * - Rule of Five (Move Semantics).
 * - Exception handling.
 *
 * @tparam T Type of elements.
 */
template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t size_count;

public:
  // --- Iterator Support ---
  /**
   * @brief Forward iterator for the linked list.
   */
  class Iterator {
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    Iterator(Node<T> *ptr) : m_ptr(ptr) {}

    reference operator*() const { return m_ptr->val; }
    pointer operator->() { return &m_ptr->val; }

    Iterator &operator++() {
      m_ptr = m_ptr->next;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(const Iterator &other) const {
      return m_ptr == other.m_ptr;
    }
    bool operator!=(const Iterator &other) const {
      return m_ptr != other.m_ptr;
    }

  private:
    Node<T> *m_ptr;
  };

  Iterator begin() { return Iterator(head); }
  Iterator end() { return Iterator(nullptr); }

  // --- Constructor / Destructor ---
  LinkedList() : head(nullptr), tail(nullptr), size_count(0) {}

  ~LinkedList() { clear(); }

  // --- Rule of Five ---

  // Copy Constructor
  LinkedList(const LinkedList &other)
      : head(nullptr), tail(nullptr), size_count(0) {
    for (const auto &val : other) {
      insertTail(val);
    }
  }

  // Copy Assignment
  LinkedList &operator=(const LinkedList &other) {
    if (this != &other) {
      clear();
      for (const auto &val : other) {
        insertTail(val);
      }
    }
    return *this;
  }

  // Move Constructor
  LinkedList(LinkedList &&other) noexcept
      : head(other.head), tail(other.tail), size_count(other.size_count) {
    other.head = nullptr;
    other.tail = nullptr;
    other.size_count = 0;
  }

  // Move Assignment
  LinkedList &operator=(LinkedList &&other) noexcept {
    if (this != &other) {
      clear(); // Clean resources
      head = other.head;
      tail = other.tail;
      size_count = other.size_count;

      other.head = nullptr;
      other.tail = nullptr;
      other.size_count = 0;
    }
    return *this;
  }

  // --- Operations ---

  /**
   * @brief Insert element at the head (Copy).
   * @param val Value to insert.
   */
  void insertHead(const T &val) {
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
    if (!tail)
      tail = newNode;
    size_count++;
  }

  /**
   * @brief Insert element at the head (Move).
   * @param val R-value to insert.
   */
  void insertHead(T &&val) {
    Node<T> *newNode = new Node<T>(std::move(val));
    newNode->next = head;
    head = newNode;
    if (!tail)
      tail = newNode;
    size_count++;
  }

  void insertTail(const T &val) {
    Node<T> *newNode = new Node<T>(val);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size_count++;
  }

  void insertTail(T &&val) {
    Node<T> *newNode = new Node<T>(std::move(val));
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size_count++;
  }

  // Get value at index (returns copy or reference? Requirements say "int
  // get(int)", so copy for primitive, but reference better for T) Requirements:
  // "int get(int i)" returns -1 if invalid. For generic T, we can't return -1.
  // We will implement `std::optional` or `T` with throw.
  // However, to satisfy the exact problem statement signature "int get(int i)",
  // we'll add a helper if T=int. Or we provide `T get(size_t index)` and throw
  // if out of bounds (Industry Standard). Let's implement `T get(size_t index)`
  // that throws.
  T get(size_t index) const {
    if (index >= size_count)
      throw std::out_of_range("Index out of bounds");
    Node<T> *curr = head;
    for (size_t i = 0; i < index; ++i)
      curr = curr->next;
    return curr->val;
  }

  bool remove(size_t index) {
    if (index >= size_count)
      return false;

    Node<T> *toDelete = nullptr;
    if (index == 0) {
      toDelete = head;
      head = head->next;
      if (size_count == 1)
        tail = nullptr;
    } else {
      Node<T> *prev = head;
      for (size_t i = 0; i < index - 1; ++i)
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

  void clear() {
    Node<T> *curr = head;
    while (curr) {
      Node<T> *next = curr->next;
      delete curr;
      curr = next;
    }
    head = nullptr;
    tail = nullptr;
    size_count = 0;
  }

  size_t size() const { return size_count; }
};

} // namespace industry

#endif // LINKED_LIST_03_INDUSTRY_STD_HPP
