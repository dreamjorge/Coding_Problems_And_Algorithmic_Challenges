#include "ThreadSafeLinkedList.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>


void worker(concurrent::ThreadSafeLinkedList &list, int id) {
  for (int i = 0; i < 10; ++i) {
    // Insert
    list.insertTail(id * 100 + i);
    // Maybe read
    if (i % 2 == 0)
      list.get(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

int main() {
  std::cout << "=== Linked List v5 (Concurrent) ===\n";

  concurrent::ThreadSafeLinkedList list;
  std::vector<std::thread> threads;

  std::cout << "Launching 4 threads doing 10 insertions each...\n";
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(worker, std::ref(list), i);
  }

  for (auto &t : threads)
    t.join();

  std::cout << "Final Size: " << list.size() << " (Expected 40)\n";

  // Validate integrity
  auto vals = list.getValues();
  std::cout << "Snapshot size: " << vals.size() << "\n";

  return 0;
}
