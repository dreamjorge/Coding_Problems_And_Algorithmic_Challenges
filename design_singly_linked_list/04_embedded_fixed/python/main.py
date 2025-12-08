from typing import List, Optional

class StaticLinkedList:
    """
    04 Embedded: Static Linked List (Object Pool)
    - Pre-allocated pool of nodes.
    - Uses indices (int) instead of references.
    """
    class Node:
        def __init__(self):
            self.val: int = 0
            self.next: int = -1

    def __init__(self, capacity: int):
        self._capacity = capacity
        self._pool = [self.Node() for _ in range(capacity)]
        
        # Initialize free list
        for i in range(capacity - 1):
            self._pool[i].next = i + 1
        self._pool[capacity - 1].next = -1
        
        self._free_head = 0
        self._head = -1
        self._tail = -1
        self._size = 0

    def _allocate(self, val: int) -> int:
        if self._free_head == -1:
            return -1 # OOM
        
        idx = self._free_head
        self._free_head = self._pool[idx].next
        
        self._pool[idx].val = val
        self._pool[idx].next = -1
        return idx

    def _deallocate(self, idx: int) -> None:
        self._pool[idx].next = self._free_head
        self._free_head = idx

    def insert_tail(self, val: int) -> bool:
        idx = self._allocate(val)
        if idx == -1:
            return False
            
        if self._head == -1:
            self._head = idx
            self._tail = idx
        else:
            self._pool[self._tail].next = idx
            self._tail = idx
            
        self._size += 1
        return True

    def remove_head(self) -> None:
        if self._head == -1:
            return
            
        to_delete = self._head
        self._head = self._pool[to_delete].next
        if self._head == -1:
            self._tail = -1
            
        self._deallocate(to_delete)
        self._size -= 1

    def print_list(self):
        print("[", end=" ")
        curr = self._head
        while curr != -1:
            print(self._pool[curr].val, end=" ")
            curr = self._pool[curr].next
        print("]")

def main():
    print("=== 04 (Embedded Fixed) Python ===")
    
    ll = StaticLinkedList(capacity=3)
    
    print("Insert 10:", ll.insert_tail(10))
    print("Insert 20:", ll.insert_tail(20))
    print("Insert 30:", ll.insert_tail(30))
    ll.print_list()
    
    print("Insert 40 (Full):", ll.insert_tail(40))
    
    print("Remove Head...")
    ll.remove_head()
    ll.print_list()
    
    print("Insert 50:", ll.insert_tail(50))
    ll.print_list()

if __name__ == "__main__":
    main()
