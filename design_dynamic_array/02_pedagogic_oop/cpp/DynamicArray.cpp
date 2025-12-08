#include "DynamicArray.h"
#include <stdexcept> // For std::out_of_range

namespace teaching {

// Constructor
/**
 * @brief Construct a new Dynamic Array object.
 *
 * @param initialCapacity Initial capacity of the array.
 */
DynamicArray::DynamicArray(size_t initialCapacity)
    : m_size(0), m_capacity(initialCapacity) {
  if (m_capacity == 0)
    m_capacity = 1; // Ensure at least some capacity
  m_data = new int[m_capacity];
}

// Initializer List Constructor
/**
 * @brief Construct a new Dynamic Array object from an initializer list.
 *
 * @param list Initializer list.
 */
DynamicArray::DynamicArray(std::initializer_list<int> list)
    : m_size(list.size()), m_capacity(list.size()) {
  if (m_capacity == 0) {
    m_capacity = 1;
    m_data = new int[m_capacity];
  } else {
    m_data = new int[m_capacity];
    size_t i = 0;
    for (int val : list) {
      m_data[i++] = val;
    }
  }
}

// Destructor
/**
 * @brief Destroy the Dynamic Array object.
 */
DynamicArray::~DynamicArray() { delete[] m_data; }

// Copy Constructor
/**
 * @brief Copy Constructor.
 *
 * @param other The object to copy from.
 */
DynamicArray::DynamicArray(const DynamicArray &other)
    : m_size(other.m_size), m_capacity(other.m_capacity) {
  m_data = new int[m_capacity];
  for (size_t i = 0; i < m_size; ++i) {
    m_data[i] = other.m_data[i];
  }
}

// Copy Assignment Operator
/**
 * @brief Copy Assignment Operator.
 *
 * @param other The object to copy from.
 * @return DynamicArray& Reference to self.
 */
DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
  if (this == &other) {
    return *this;
  }

  // Strong Exception Guarantee (Basic version: allocate first)
  int *newData = new int[other.m_capacity];
  for (size_t i = 0; i < other.m_size; ++i) {
    newData[i] = other.m_data[i];
  }

  delete[] m_data;
  m_data = newData;
  m_size = other.m_size;
  m_capacity = other.m_capacity;

  return *this;
}

// Push Back
/**
 * @brief Add an element to the end of the array.
 *
 * @param value The value to add.
 */
void DynamicArray::push_back(int value) {
  if (m_size == m_capacity) {
    resize();
  }
  m_data[m_size++] = value;
}

// Pop Back
/**
 * @brief Remove the last element from the array.
 */
void DynamicArray::pop_back() {
  if (m_size > 0) {
    m_size--;
  }
}

// Operator [] (Read/Write)
/**
 * @brief Access element at index.
 *
 * @param index Index to access.
 * @return int& Reference to the element.
 * @throws std::out_of_range If index is out of bounds.
 */
int &DynamicArray::operator[](size_t index) {
  if (index >= m_size) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[index];
}

// Operator [] (Read-only)
/**
 * @brief Access element at index (Const).
 *
 * @param index Index to access.
 * @return const int& Const reference to the element.
 * @throws std::out_of_range If index is out of bounds.
 */
const int &DynamicArray::operator[](size_t index) const {
  if (index >= m_size) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[index];
}

// Getters
size_t DynamicArray::size() const { return m_size; }
size_t DynamicArray::capacity() const { return m_capacity; }

// Resize
void DynamicArray::resize() {
  size_t newCapacity = m_capacity * 2;
  int *newData = new int[newCapacity];

  for (size_t i = 0; i < m_size; ++i) {
    newData[i] = m_data[i];
  }

  delete[] m_data;
  m_data = newData;
  m_capacity = newCapacity;
}

// Output Stream Operator
std::ostream &operator<<(std::ostream &os, const DynamicArray &arr) {
  os << "{ ";
  for (size_t i = 0; i < arr.m_size; ++i) {
    os << arr.m_data[i] << (i < arr.m_size - 1 ? ", " : "");
  }
  os << " }";
  return os;
}

} // namespace teaching
