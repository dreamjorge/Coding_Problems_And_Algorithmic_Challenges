#ifndef DYNAMIC_ARRAY_02_PEDAGOGIC_H
#define DYNAMIC_ARRAY_02_PEDAGOGIC_H

#include <initializer_list>
#include <iostream>

// ============================================================================
// ============================================================================
// 02: PEDAGOGIC IMPROVEMENT
// Goal: Teach best software engineering practices.
// Features:
// - Separation of Interface (.h) and Implementation (.cpp).
// - Namespace usage.
// - Const correctness.
// - Operator overloading ([], <<).
// - Initializer list support.
// ============================================================================

namespace teaching {

/**
 * @brief A dynamic array implementation focused on teaching C++ best practices.
 *
 * Features explicit memory management with Rule of Three, const correctness,
 * and namespaces.
 */
class DynamicArray {
private:
  int *m_data;   // Prefix member variables with m_
  size_t m_size; // Use size_t for sizes
  size_t m_capacity;

public:
  // Constructor
  /**
   * @brief Construct a new Dynamic Array object.
   *
   * @param initialCapacity Initial capacity of the array.
   */
  explicit DynamicArray(size_t initialCapacity = 2);

  // Initializer List Constructor (e.g., DynamicArray arr = {1, 2, 3};)
  /**
   * @brief Construct a new Dynamic Array object from an initializer list.
   *
   * @param list Initializer list of integers.
   */
  DynamicArray(std::initializer_list<int> list);

  // Destructor
  ~DynamicArray();

  // Copy Constructor
  DynamicArray(const DynamicArray &other);

  // Copy Assignment Operator
  DynamicArray &operator=(const DynamicArray &other);

  // Add element
  void push_back(int value);

  // Remove element (from end)
  void pop_back();

  // Access element (read/write)
  int &operator[](size_t index);

  // Access element (read-only)
  const int &operator[](size_t index) const;

  // Getters
  size_t size() const;
  size_t capacity() const;

  // Print helper (friend function to allow std::cout << arr)
  friend std::ostream &operator<<(std::ostream &os, const DynamicArray &arr);

private:
  void resize();
};

} // namespace teaching

#endif // DYNAMIC_ARRAY_02_PEDAGOGIC_H
