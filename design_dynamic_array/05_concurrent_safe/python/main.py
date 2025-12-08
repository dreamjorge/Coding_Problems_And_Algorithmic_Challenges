import threading
import time
from typing import TypeVar, Generic, List

T = TypeVar('T')

class ThreadSafeVector(Generic[T]):
    """
    05 Concurrent: Thread Safe Vector
    - Protected by a Lock (Mutex)
    """
    def __init__(self):
        self._data: List[T] = []
        self._lock = threading.Lock()

    def push_back(self, val: T) -> None:
        with self._lock:
            self._data.append(val)

    def size(self) -> int:
        with self._lock:
            return len(self._data)
            
    def get_snapshot(self) -> List[T]:
        with self._lock:
            return list(self._data) # Return copy

def worker(vec: ThreadSafeVector, id: int):
    for i in range(10):
        vec.push_back(f"Thread{id}-{i}")
        time.sleep(0.001) # Simulate work

def main():
    print("=== 05 (Concurrent Safe) Python ===")
    
    vec = ThreadSafeVector[str]()
    threads = []
    
    print("Launching 4 threads...")
    for i in range(4):
        t = threading.Thread(target=worker, args=(vec, i))
        threads.append(t)
        t.start()
        
    for t in threads:
        t.join()
        
    print(f"Final Size: {vec.size()} (Expected 40)")
    
    # Snapshot
    snap = vec.get_snapshot()
    print(f"Snapshot Sample: {snap[:3]} ...")

if __name__ == "__main__":
    main()
