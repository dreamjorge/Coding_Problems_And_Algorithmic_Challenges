from typing import Optional, List

class Node:
    def __init__(self, val: int):
        self.val = val
        self.next: Optional['Node'] = None

class LinkedList:
    """
    02 Pedagogic: Encapsulated Linked List
    """
    def __init__(self):
        self._head: Optional[Node] = None
        self._tail: Optional[Node] = None
        self._size: int = 0

    def insert_head(self, val: int) -> None:
        new_node = Node(val)
        new_node.next = self._head
        self._head = new_node
        if self._size == 0:
            self._tail = new_node
        self._size += 1

    def insert_tail(self, val: int) -> None:
        new_node = Node(val)
        if self._size == 0:
            self._head = new_node
            self._tail = new_node
        else:
            self._tail.next = new_node
            self._tail = new_node
        self._size += 1

    def get_values(self) -> List[int]:
        res = []
        curr = self._head
        while curr:
            res.append(curr.val)
            curr = curr.next
        return res

def main():
    print("=== 02 (Pedagogic OOP) Python ===")
    
    ll = LinkedList()
    ll.insert_head(10)
    ll.insert_tail(20)
    ll.insert_tail(30)
    
    print("List:", ll.get_values())

if __name__ == "__main__":
    main()
