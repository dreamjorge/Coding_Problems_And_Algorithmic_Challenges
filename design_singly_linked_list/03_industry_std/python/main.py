from typing import TypeVar, Generic, Optional, Iterator, Iterable

T = TypeVar('T')

class Node(Generic[T]):
    def __init__(self, val: T):
        self.val = val
        self.next: Optional['Node[T]'] = None

class LinkedList(Generic[T]):
    """
    03 Industry: Pythonic Linked List
    - Supports iteration (for x in list)
    - Generic Type T
    """
    def __init__(self, iterable: Iterable[T] = None):
        self._head: Optional[Node[T]] = None
        self._tail: Optional[Node[T]] = None
        self._size: int = 0
        
        if iterable:
            for item in iterable:
                self.insert_tail(item)

    def insert_tail(self, val: T) -> None:
        new_node = Node(val)
        if not self._head:
            self._head = new_node
            self._tail = new_node
        else:
            self._tail.next = new_node
            self._tail = new_node
        self._size += 1

    def __iter__(self) -> Iterator[T]:
        curr = self._head
        while curr:
            yield curr.val
            curr = curr.next

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        return " -> ".join(str(x) for x in self)

def main():
    print("=== 03 (Industry Std) Python ===")
    
    ll = LinkedList([1, 2, 3])
    print(f"Init: {ll}")
    
    ll.insert_tail(4)
    print("Iterating:")
    for x in ll:
        print(f" - {x}")

if __name__ == "__main__":
    main()
