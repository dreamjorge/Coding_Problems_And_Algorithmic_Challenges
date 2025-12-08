#ifndef LINKED_LIST_04_EMBEDDED_FIXED_HPP
#define LINKED_LIST_04_EMBEDDED_FIXED_HPP

#include <array>
#include <cstdint>
#include <iostream>

namespace embedded {

/**
 * @brief Static Singly Linked List for Embedded Systems.
 *
 * Uses a fixed-size std::array as a node pool to avoid heap allocation.
 * Uses index-based linking (int16_t) instead of pointers.
 *
 * @tparam T Type of elements.
 * @tparam Capacity Maximum number of nodes.
 */
template <typename T, size_t Capacity> class StaticLinkedList {
private:
  struct Node {
    T val;
    int16_t next; // Index of next node, -1 for null
  };

  std::array<Node, Capacity> pool;
  int16_t head;
  int16_t tail;
  int16_t free_head; // Head of the "free list"
  size_t size_count;

public:
  StaticLinkedList() : head(-1), tail(-1), free_head(0), size_count(0) {
    // Initialize free list
    for (size_t i = 0; i < Capacity - 1; ++i) {
      pool[i].next = static_cast<int16_t>(i + 1);
    }
    pool[Capacity - 1].next = -1; // Last one null
  }

  // Allocate a node from the pool (O(1))
  /**
   * @brief Allocates a node from the free list.
   * @param val Value to store.
   * @return int16_t Index of the allocated node, or -1 if full.
   */
  int16_t allocate(const T &val) {
    if (free_head == -1)
      return -1; // OOM

    int16_t newIndex = free_head;
    free_head = pool[free_head].next;

    pool[newIndex].val = val;
    pool[newIndex].next = -1;
    return newIndex;
  }

  // Free a node back to the pool (O(1))
  void deallocate(int16_t index) {
    pool[index].next = free_head;
    free_head = index;
  }

  // Insert Head
  bool insertHead(const T &val) {
    int16_t newNodeParams = allocate(val);
    if (newNodeParams == -1)
      return false;

    pool[newNodeParams].next = head;
    head = newNodeParams;
    if (tail == -1)
      tail = newNodeParams;
    size_count++;
    return true;
  }

  // Insert Tail
  bool insertTail(const T &val) {
    int16_t newIndex = allocate(val);
    if (newIndex == -1)
      return false;

    if (tail == -1) {
      head = newIndex;
      tail = newIndex;
    } else {
      pool[tail].next = newIndex;
      tail = newIndex;
    }
    size_count++;
    return true;
  }

  // Remove index (linear walk logic)
  // Note: 'index' here is logical index (0th, 1st...), not physical pool index.
  bool remove(size_t logicalIndex) {
    if (logicalIndex >= size_count)
      return false;

    int16_t toDelete = -1;

    if (logicalIndex == 0) {
      toDelete = head;
      head = pool[head].next;
      if (size_count == 1)
        tail = -1;
    } else {
      int16_t prev = head;
      for (size_t i = 0; i < logicalIndex - 1; ++i) {
        prev = pool[prev].next;
      }
      toDelete = pool[prev].next;
      pool[prev].next = pool[toDelete].next;

      if (logicalIndex == size_count - 1) {
        tail = prev;
      }
    }

    deallocate(toDelete);
    size_count--;
    return true;
  }

  T *get(size_t logicalIndex) {
    if (logicalIndex >= size_count)
      return nullptr;

    int16_t curr = head;
    for (size_t i = 0; i < logicalIndex; ++i) {
      curr = pool[curr].next;
    }
    return &pool[curr].val;
  }

  size_t size() const { return size_count; }
  size_t capacity() const { return Capacity; }

  // Print helper
  void print() {
    std::cout << "[ ";
    int16_t curr = head;
    while (curr != -1) {
      std::cout << pool[curr].val << " ";
      curr = pool[curr].next;
    }
    std::cout << "]\n";
  }
};

} // namespace embedded

#endif // LINKED_LIST_04_EMBEDDED_FIXED_HPP
