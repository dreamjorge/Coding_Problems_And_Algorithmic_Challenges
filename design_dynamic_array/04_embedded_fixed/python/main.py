from typing import TypeVar, Generic, List, Optional

T = TypeVar('T')

class FixedVector(Generic[T]):
    """
    04 Embedded: Fixed Capacity Vector
    - No implicit resizing (heap fragmentation avoidance)
    - Returns False on failure instead of Exceptions (System Safe)
    """
    def __init__(self, capacity: int):
        self._capacity = capacity
        self._size = 0
        self._data: List[Optional[T]] = [None] * capacity

    def push_back(self, val: T) -> bool:
        if self._size >= self._capacity:
            return False # Overflow!
        
        self._data[self._size] = val
        self._size += 1
        return True

    def pop_back(self) -> None:
        if self._size > 0:
            self._size -= 1
            self._data[self._size] = None

    def get(self, index: int) -> Optional[T]:
        if index < 0 or index >= self._size:
            return None # Invalid access
        return self._data[index]

    def size(self) -> int:
        return self._size
    
    def capacity(self) -> int:
        return self._capacity

    def __str__(self) -> str:
        return f"{self._data[:self._size]} (Cap: {self._capacity})"

def main():
    print("=== 04 (Embedded Fixed) Python ===")
    
    vec = FixedVector[int](capacity=3)
    
    print("Push 10:", vec.push_back(10))
    print("Push 20:", vec.push_back(20))
    print("Push 30:", vec.push_back(30))
    print("State:", vec)
    
    print("Push 40 (Should Fail):", vec.push_back(40))
    
    print("Pop back...")
    vec.pop_back()
    print("Push 50:", vec.push_back(50))
    print("State:", vec)

if __name__ == "__main__":
    main()
