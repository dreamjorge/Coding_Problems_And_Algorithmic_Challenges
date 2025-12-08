#include "ThreadSafeLinkedList.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void worker(concurrent::ThreadSafeLinkedList &list, int id) {
  for (int i = 0; i < 10; ++i) {
    // Insert
    list.insertTail(id * 100 + i);
    // Simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    // Reader test logic could go here
    if (i % 5 == 0) {
      list.get(0);
    }
  }
}

int main() {
  std::cout << "=== 05 (Concurrent Safe) ===\n";

  concurrent::ThreadSafeLinkedList list;
  std::vector<std::thread> threads;

  std::cout << "Launching 4 threads...\n";
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(worker, std::ref(list), i);
  }

  for (auto &t : threads)
    t.join();

  std::cout << "Final Size: " << list.size() << " (Expected 40)\n";

  // Validate integrity
  auto vals = list.getValues();
  std::cout << "Snapshot size: " << vals.size() << "\n";

  if (vals.size() > 0) {
    std::cout << "Sample: " << vals[0] << " ... " << vals.back() << "\n";
  }

  return 0;
}
