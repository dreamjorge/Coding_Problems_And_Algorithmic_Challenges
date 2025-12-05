#include <iostream>

// ============================================================================
// VERSION 1: STUDENT LEARNING
// Goal: Understand memory management, pointers, and the "Rule of Three".
// Features:
// - Simple "int" array (no templates).
// - "Logging" to console to see exactly when memory is allocated/freed.
// - All in one file for easy reading.
//
// Compilation:
//   g++ main.cpp -o v1_student
//   ./v1_student
// ============================================================================

class DynamicArray {
private:
  int *data;    // Pointer to the heap memory
  int size;     // Number of elements currently used
  int capacity; // Total number of elements we can hold before resizing

public:
  // 1. Constructor
  // Allocates initial memory.
  explicit DynamicArray(int initialCapacity = 2)
      : size(0), capacity(initialCapacity) {
    data = new int[capacity];
    std::cout << "[Constructor] Allocated memory for " << capacity
              << " ints at " << data << ".\n";
  }

  // 2. Destructor
  // Frees memory when the object is destroyed.
  ~DynamicArray() {
    std::cout << "[Destructor] Releasing memory at " << data << ".\n";
    delete[] data;
  }

  // 3. Copy Constructor (Rule of Three Part 1)
  // Creates a new object as a deep copy of an existing one.
  DynamicArray(const DynamicArray &other)
      : size(other.size), capacity(other.capacity) {
    data = new int[capacity]; // Allocate NEW memory
    std::cout << "[Copy Constructor] Copying " << size << " elements from "
              << other.data << " to " << data << ".\n";
    for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }

  // 4. Copy Assignment Operator (Rule of Three Part 2)
  // Updates an existing object to be a deep copy of another.
  DynamicArray &operator=(const DynamicArray &other) {
    std::cout << "[Assignment Operator] Called.\n";

    if (this == &other) {
      return *this; // Self-assignment check
    }

    // Clean up old memory
    delete[] data;

    // Allocate new memory and copy
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];

    for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }

    return *this;
  }

  // Add an element to the end
  void pushback(int n) {
    if (size == capacity) {
      resize();
    }
    data[size] = n;
    size++;
    std::cout << "  -> Pushed " << n << ". Size: " << size << "/" << capacity
              << "\n";
  }

  // Return the element at index i
  int get(int i) const {
    if (i < 0 || i >= size) {
      // In a real scenario, this is undefined behavior or throws.
      // For v1 student level, we might just return -1 or 0 with a warning.
      std::cout << "[Error] Index out of bounds!\n";
      return -1;
    }
    return data[i];
  }

  // Set the element at index i to n
  void set(int i, int n) {
    if (i < 0 || i >= size) {
      std::cout << "[Error] Index out of bounds!\n";
      return;
    }
    data[i] = n;
  }

  // Pop and return the element at the end of the array
  int popback() {
    if (size > 0) {
      size--;
      return data[size];
    }
    std::cout << "[Error] Pop from empty array!\n";
    return -1;
  }

  // Return the number of elements
  int getSize() const { return size; }

  // Return the capacity
  int getCapacity() const { return capacity; }

  // Print array contents
  void print() const {
    std::cout << "  [Array Content] { ";
    for (int i = 0; i < size; ++i) {
      std::cout << data[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << " }\n";
  }

private:
  // Helper to double the capacity
  void resize() {
    int newCapacity = capacity * 2;
    std::cout << "    [Resize] Growing from " << capacity << " to "
              << newCapacity << ".\n";

    int *newData = new int[newCapacity]; // 1. Allocate new
    for (int i = 0; i < size; ++i) {
      newData[i] = data[i]; // 2. Copy old
    }
    delete[] data;  // 3. Delete old
    data = newData; // 4. Point to new
    capacity = newCapacity;
  }
};

int main() {
  std::cout << "=== 1. Creation ===\n";
  DynamicArray arr(2);
  arr.pushback(10);
  arr.pushback(20);
  arr.print();
  std::cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity()
            << "\n";

  std::cout << "\n=== 2. Resize Trigger ===\n";
  arr.pushback(30); // Triggers resize
  arr.print();
  std::cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity()
            << "\n";

  std::cout << "\n=== 3. Get/Set/Pop ===\n";
  arr.set(0, 999);
  std::cout << "Set index 0 to 999. Get(0): " << arr.get(0) << "\n";
  int popped = arr.popback();
  std::cout << "Popped: " << popped << "\n";
  arr.print();

  std::cout << "\n=== 4. Copy Constructor ===\n";
  {
    DynamicArray copy = arr; // Calls Copy Constructor
    copy.pushback(88);
    std::cout << "Original: ";
    arr.print();
    std::cout << "Copy:     ";
    copy.print();
  } // copy is destroyed here

  std::cout << "\n=== 5. Assignment Operator ===\n";
  DynamicArray arr2(5);
  arr2 = arr; // Calls Assignment Operator
  arr2.print();

  std::cout << "\n=== End of Main ===\n";
  return 0;
}
