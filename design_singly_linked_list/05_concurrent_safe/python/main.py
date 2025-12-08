import threading
import time
from typing import Optional, List

class ThreadSafeLinkedList:
    """
    05 Concurrent: Thread Safe Linked List
    """
    class Node:
        def __init__(self, val: int):
            self.val = val
            self.next: Optional[ThreadSafeLinkedList.Node] = None

    def __init__(self):
        self._head: Optional[ThreadSafeLinkedList.Node] = None
        self._tail: Optional[ThreadSafeLinkedList.Node] = None
        self._lock = threading.RLock()
        self._size = 0

    def insert_tail(self, val: int) -> None:
        with self._lock:
            new_node = self.Node(val)
            if not self._head:
                self._head = new_node
                self._tail = new_node
            else:
                self._tail.next = new_node
                self._tail = new_node
            self._size += 1

    def get_values(self) -> List[int]:
        with self._lock:
            res = []
            curr = self._head
            while curr:
                res.append(curr.val)
                curr = curr.next
            return res

    def size(self) -> int:
        with self._lock:
            return self._size

def worker(ll: ThreadSafeLinkedList, id: int):
    for i in range(10):
        ll.insert_tail(id * 100 + i)
        time.sleep(0.001)

def main():
    print("=== 05 (Concurrent Safe) Python ===")
    
    ll = ThreadSafeLinkedList()
    threads = []
    
    print("Launching 4 threads...")
    for i in range(4):
        t = threading.Thread(target=worker, args=(ll, i))
        threads.append(t)
        t.start()
        
    for t in threads:
        t.join()
        
    print(f"Final Size: {ll.size()} (Expected 40)")
    vals = ll.get_values()
    print(f"Sample: {vals[:5]} ...")

if __name__ == "__main__":
    main()
