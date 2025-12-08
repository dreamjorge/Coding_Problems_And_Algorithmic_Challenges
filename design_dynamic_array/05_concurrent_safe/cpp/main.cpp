#include "ThreadSafeVector.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

// Simulate a worker thread
void worker(int id, concurrent::ThreadSafeVector<int> &vec) {
  for (int i = 0; i < 5; ++i) {
    // Sleep to simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // Concurrent Write
    vec.push_back(id * 100 + i);

    // Concurrent Read
    // std::cout is NOT thread safe, so output might look messy without its own
    // mutex, but the Vector itself is safe.
  }
}

int main() {
  std::cout << "=== 05 (Concurrent Safe) ===\n";

  concurrent::ThreadSafeVector<int> sharedVec;
  std::vector<std::thread> threads;

  // Launch 4 threads
  std::cout << "Launching 4 threads writing simultaneously...\n";
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(worker, i + 1, std::ref(sharedVec));
  }

  // Wait for them
  for (auto &t : threads) {
    t.join();
  }

  std::cout << "All threads finished. Final Size: " << sharedVec.size()
            << " (Expected 20)\n";

  // Verify contents
  auto snapshot = sharedVec.get_snapshot();
  std::cout << "Content Sample: ";
  for (size_t i = 0; i < snapshot.size(); ++i) {
    if (i < 10)
      std::cout << snapshot[i] << " ";
  }
  std::cout << "...\n";

  return 0;
}
