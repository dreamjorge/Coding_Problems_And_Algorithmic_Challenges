#ifndef THREAD_SAFE_VECTOR_HPP
#define THREAD_SAFE_VECTOR_HPP

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>


// ============================================================================
// VERSION 5: CONCURRENT / MULTI-THREADED
// Goal: Thread safety in a multi-core environment.
// Features:
// - Internal Mutex.
// - Thread-safe push_back.
// - Thread-safe access (Read-Write Locks).
// ============================================================================

namespace concurrent {

template <typename T> class ThreadSafeVector {
private:
  std::vector<T> m_data;             // Underlying container
  mutable std::shared_mutex m_mutex; // C++17 R/W Lock mechanism

public:
  ThreadSafeVector() = default;

  // Thread-Safe Writer
  void push_back(const T &value) {
    std::unique_lock<std::shared_mutex> lock(m_mutex); // Exclusive Lock
    m_data.push_back(value);
    // Lock releases automatically
  }

  // Thread-Safe Writer
  void pop_back() {
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    if (!m_data.empty()) {
      m_data.pop_back();
    }
  }

  // Thread-Safe Reader
  // Copy the value to ensure safety after lock release
  T get(size_t index) const {
    std::shared_lock<std::shared_mutex> lock(
        m_mutex); // Shared Lock (Multiple readers allowed)
    if (index >= m_data.size()) {
      throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
  }

  // Snapshot
  // Returns a COPY of the entire vector for thread-safe iteration
  std::vector<T> get_snapshot() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    return m_data; // Copy Constructor
  }

  size_t size() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    return m_data.size();
  }
};

} // namespace concurrent

#endif // THREAD_SAFE_VECTOR_HPP
