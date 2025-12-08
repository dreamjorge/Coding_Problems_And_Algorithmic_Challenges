
import sys

def main():
    print("=== 01 (Student Intro) Python ===")
    
    # 1. Initialize
    capacity = 2
    size = 0
    data = [None] * capacity  # Simulating raw memory
    
    # Helper to print state
    def print_state():
        print(f"Size: {size}, Capacity: {capacity}, Data: {data[:size]}")

    print("--- Initial State ---")
    print_state()

    # 2. Add Elements (Push Back)
    print("\n--- Adding Elements ---")
    elements_to_add = [10, 20, 30, 40, 50]
    
    for val in elements_to_add:
        print(f"Pushing {val}...")
        
        # Check Resize
        if size == capacity:
            print(f"    [Resize] Growing from {capacity} to {capacity * 2}.")
            new_capacity = capacity * 2
            new_data = [None] * new_capacity
            
            # Copy old
            for i in range(size):
                new_data[i] = data[i]
                
            data = new_data
            capacity = new_capacity
            
        # Add Element
        data[size] = val
        size += 1
        print_state()

    # 3. Access Elements
    print("\n--- Accessing Elements ---")
    print(f"Index 2: {data[2]}")
    
    try:
        # Python lists throw IndexError, but in C++ raw array access is unsafe.
        # We simulate careful bounds checking logic here.
        if 10 >= size:
            print("Index 10 out of bounds!")
    except IndexError:
        pass

if __name__ == "__main__":
    main()
