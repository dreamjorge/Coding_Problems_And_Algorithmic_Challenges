from collections.abc import MutableSequence
from typing import TypeVar, Generic, List, Iterator, Union, Iterable

T = TypeVar('T')

class DynamicArray(MutableSequence[T]):
    """
    03 Industry Standard: Pythonic Dynamic Array
    - Implements MutableSequence (works like a standard list)
    - Supports iterators, slicing, etc.
    """
    def __init__(self, iterable: Iterable[T] = None):
        self._data: List[T] = []
        if iterable:
            self._data.extend(iterable)

    # --- MutableSequence Requirements ---

    def __getitem__(self, index: Union[int, slice]) -> Union[T, List[T]]:
        return self._data[index]

    def __setitem__(self, index: int, value: T) -> None:
        self._data[index] = value

    def __delitem__(self, index: int) -> None:
        del self._data[index]

    def __len__(self) -> int:
        return len(self._data)

    def insert(self, index: int, value: T) -> None:
        self._data.insert(index, value)

    # --- Extra ---

    def __iter__(self) -> Iterator[T]:
        return iter(self._data)

    def __str__(self) -> str:
        return str(self._data)

def main():
    print("=== 03 (Industry Std) Python ===")
    
    # 1. Initialization
    vec = DynamicArray([1, 2, 3])
    print(f"Init: {vec}")
    
    # 2. Append (from MutableSequence)
    vec.append(4)
    print(f"Append: {vec}")
    
    # 3. Iteration
    print("Iterate: ", end="")
    for x in vec:
        print(x, end=" ")
    print()
    
    # 4. Slicing
    print(f"Slice [1:3]: {vec[1:3]}")
    
    # 5. Delete
    del vec[0]
    print(f"Delete index 0: {vec}")

if __name__ == "__main__":
    main()
