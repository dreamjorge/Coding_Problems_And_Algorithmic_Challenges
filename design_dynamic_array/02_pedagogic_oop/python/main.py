from typing import List, Optional, TypeVar, Generic

T = TypeVar('T')

class DynamicArray(Generic[T]):
    """
    02 Pedagogic: Encapsulated Dynamic Array
    Focus on Correctness, Encapsulation, and easy-to-read code.
    """
    def __init__(self):
        self._capacity: int = 2
        self._size: int = 0
        self._data: List[Optional[T]] = [None] * self._capacity

    def push_back(self, val: T) -> None:
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        
        self._data[self._size] = val
        self._size += 1

    def pop_back(self) -> None:
        if self._size > 0:
            self._size -= 1
            self._data[self._size] = None # Help GC

    def get(self, index: int) -> T:
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        return self._data[index] # type: ignore

    def size(self) -> int:
        return self._size

    def capacity(self) -> int:
        return self._capacity

    def is_empty(self) -> bool:
        return self._size == 0

    def _resize(self, new_capacity: int) -> None:
        print(f"    [Resize] {self._capacity} -> {new_capacity}")
        new_data: List[Optional[T]] = [None] * new_capacity
        for i in range(self._size):
            new_data[i] = self._data[i]
        self._data = new_data
        self._capacity = new_capacity

    def __str__(self) -> str:
        # Only show active elements
        active_elements = [str(self._data[i]) for i in range(self._size)]
        return f"[{', '.join(active_elements)}]"

def main():
    print("=== 02 (Pedagogic OOP) Python ===")
    
    arr = DynamicArray[int]()
    print("Is empty?", arr.is_empty())
    
    print("Pushing 10, 20, 30...")
    arr.push_back(10)
    arr.push_back(20)
    arr.push_back(30) # Triggers resize
    
    print("Array:", arr)
    print("Size:", arr.size())
    print("Capacity:", arr.capacity())
    
    print("Pop back...")
    arr.pop_back()
    print("Array:", arr)
    
    try:
        print("Get 5:", arr.get(5))
    except IndexError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
