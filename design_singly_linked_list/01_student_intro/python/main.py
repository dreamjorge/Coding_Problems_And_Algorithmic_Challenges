class Node:
    def __init__(self, val: int):
        self.val = val
        self.next = None

def main():
    print("=== 01 (Student Intro) Python ===")
    
    # 1. Initialize Head
    head = Node(1)
    
    # 2. Add Element (Insert Tail)
    # Basic traversal
    curr = head
    while curr.next:
        curr = curr.next
    curr.next = Node(2)

    # 3. Add Element (Insert Head)
    new_node = Node(0)
    new_node.next = head
    head = new_node
    
    # 4. Print
    print("Values: [", end=" ")
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print("]")

    # 5. Remove '1' (which is at index 1 now: 0 -> 1 -> 2)
    print("Removing element at index 1...")
    
    # Needs to find prev
    prev = head
    # We want to remove index 1, so prev is index 0
    to_delete = prev.next
    prev.next = to_delete.next
    # Python GC handles 'to_delete'

    # Print Again
    print("Values: [", end=" ")
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print("]")

if __name__ == "__main__":
    main()
