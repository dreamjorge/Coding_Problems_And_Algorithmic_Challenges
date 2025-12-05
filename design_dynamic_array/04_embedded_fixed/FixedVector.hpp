#ifndef FIXED_VECTOR_HPP
#define FIXED_VECTOR_HPP

#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>


// ============================================================================
// VERSION 4: EMBEDDED / LOW-LATENCY
// Goal: Deterministic memory usage, strict safety, no heap allocation.
// Features:
// - Fixed capacity (template argument).
// - No 'new'/'delete'.
// - Error codes instead of exceptions (optional, for strict environments).
// ============================================================================

namespace embedded {

template <typename T, size_t Capacity> class FixedVector {
private:
  std::array<T, Capacity> m_data; // Allocated on Stack (or BSS if static)
  size_t m_size = 0;

public:
  // O(1) Push
  // Returns false if full (instead of throwing/resizing)
  bool push_back(const T &value) {
    if (m_size >= Capacity) {
      return false; // Error: Overflow
    }
    m_data[m_size++] = value;
    return true;
  }

  // O(1) Pop
  void pop_back() {
    if (m_size > 0) {
      m_size--;
      // Destruct T if complex?
      // In embedded C++, we often use Trivial types.
    }
  }

  // Accessors
  T &operator[](size_t index) {
    // No checks in release, use .at() for debug
    return m_data[index];
  }

  const T &operator[](size_t index) const { return m_data[index]; }

  // Safe Access
  T *at(size_t index) {
    if (index >= m_size)
      return nullptr;
    return &m_data[index];
  }

  size_t size() const { return m_size; }
  size_t capacity() const { return Capacity; }
  bool full() const { return m_size == Capacity; }
  bool empty() const { return m_size == 0; }

  // Iterators (Standard C++ compliance)
  T *begin() { return m_data.data(); }
  T *end() { return m_data.data() + m_size; }
  const T *begin() const { return m_data.data(); }
  const T *end() const { return m_data.data() + m_size; }
};

} // namespace embedded

#endif // FIXED_VECTOR_HPP
