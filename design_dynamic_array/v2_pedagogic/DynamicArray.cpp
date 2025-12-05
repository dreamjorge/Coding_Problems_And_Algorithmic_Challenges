#include "DynamicArray.h"
#include <stdexcept> // For std::out_of_range

namespace teaching {

// Constructor
DynamicArray::DynamicArray(size_t initialCapacity)
    : m_size(0), m_capacity(initialCapacity) {
  if (m_capacity == 0)
    m_capacity = 1; // Ensure at least some capacity
  m_data = new int[m_capacity];
}

// Initializer List Constructor
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
DynamicArray::~DynamicArray() { delete[] m_data; }

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray &other)
    : m_size(other.m_size), m_capacity(other.m_capacity) {
  m_data = new int[m_capacity];
  for (size_t i = 0; i < m_size; ++i) {
    m_data[i] = other.m_data[i];
  }
}

// Copy Assignment Operator
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
void DynamicArray::push_back(int value) {
  if (m_size == m_capacity) {
    resize();
  }
  m_data[m_size++] = value;
}

// Operator [] (Read/Write)
int &DynamicArray::operator[](size_t index) {
  if (index >= m_size) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[index];
}

// Operator [] (Read-only)
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
