#ifndef DYNAMIC_ARRAY_V3_HPP
#define DYNAMIC_ARRAY_V3_HPP

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>

// ============================================================================
// VERSION 3: REAL-WORLD INDUSTRY
// Goal: Performance, flexibility, and robustness.
// Features:
// - Templates (Generic programming).
// - Rule of Five (Move Constructor, Move Assignment).
// - Iterators (begin/end).
// - Strong Exception Guarantee (where possible).
// - std::allocator (implied via new[] for simplicity, but designed for it).
// ============================================================================

namespace industry {

template <typename T> class DynamicArray {
private:
  T *m_data;
  size_t m_size;
  size_t m_capacity;

public:
  // --- Constructors & Destructor ---

  explicit DynamicArray(size_t initialCapacity = 2)
      : m_data(nullptr), m_size(0), m_capacity(initialCapacity) {
    if (m_capacity > 0) {
      m_data = new T[m_capacity];
    }
  }

  DynamicArray(std::initializer_list<T> list)
      : m_size(list.size()), m_capacity(list.size()) {
    m_data = new T[m_capacity];
    std::copy(list.begin(), list.end(), m_data);
  }

  ~DynamicArray() { delete[] m_data; }

  // --- Rule of Five ---

  // 1. Copy Constructor
  DynamicArray(const DynamicArray &other)
      : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
  }

  // 2. Copy Assignment
  DynamicArray &operator=(const DynamicArray &other) {
    if (this != &other) {
      T *newData = new T[other.m_capacity];
      std::copy(other.m_data, other.m_data + other.m_size, newData);
      delete[] m_data;
      m_data = newData;
      m_size = other.m_size;
      m_capacity = other.m_capacity;
    }
    return *this;
  }

  // 3. Move Constructor
  DynamicArray(DynamicArray &&other) noexcept
      : m_data(other.m_data), m_size(other.m_size),
        m_capacity(other.m_capacity) {
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
  }

  // 4. Move Assignment
  DynamicArray &operator=(DynamicArray &&other) noexcept {
    if (this != &other) {
      delete[] m_data;
      m_data = other.m_data;
      m_size = other.m_size;
      m_capacity = other.m_capacity;

      other.m_data = nullptr;
      other.m_size = 0;
      other.m_capacity = 0;
    }
    return *this;
  }

  // --- Core Functionality ---

  void push_back(const T &value) {
    if (m_size == m_capacity) {
      resize();
    }
    m_data[m_size++] = value;
  }

  void push_back(T &&value) {
    if (m_size == m_capacity) {
      resize();
    }
    m_data[m_size++] = std::move(value);
  }

  void pop_back() {
    if (m_size > 0) {
      m_size--;
      // For complex types, we would also:
      // m_data[m_size].~T();
      // But since we use simple new T[], the object isn't actually destroyed
      // here in the raw memory sense, but for the array logic, it's "gone".
    }
  }

  template <typename... Args> void emplace_back(Args &&...args) {
    if (m_size == m_capacity) {
      resize();
    }
    // Construct in-place (simplified for array, usually requires placement new)
    // For raw array of objects, they are already default constructed.
    // We just assign. Ideally we'd use raw memory + placement new.
    m_data[m_size++] = T(std::forward<Args>(args)...);
  }

  // --- Accessors ---

  T &operator[](size_t index) {
    return m_data[index]; // No bounds check for speed (industry standard
                          // usually provides .at() for check)
  }

  const T &operator[](size_t index) const { return m_data[index]; }

  T &at(size_t index) {
    if (index >= m_size)
      throw std::out_of_range("Index out of bounds");
    return m_data[index];
  }

  const T &at(size_t index) const {
    if (index >= m_size)
      throw std::out_of_range("Index out of bounds");
    return m_data[index];
  }

  size_t size() const noexcept { return m_size; }
  size_t capacity() const noexcept { return m_capacity; }
  bool empty() const noexcept { return m_size == 0; }

  // --- Iterators ---
  using iterator = T *;
  using const_iterator = const T *;

  iterator begin() { return m_data; }
  iterator end() { return m_data + m_size; }
  const_iterator begin() const { return m_data; }
  const_iterator end() const { return m_data + m_size; }

private:
  void resize() {
    size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
    T *newData = new T[newCapacity];

    // Move if noexcept, otherwise copy (Strong Exception Guarantee)
    for (size_t i = 0; i < m_size; ++i) {
      newData[i] = std::move_if_noexcept(m_data[i]);
    }

    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
  }
};

} // namespace industry

#endif // DYNAMIC_ARRAY_V3_HPP
