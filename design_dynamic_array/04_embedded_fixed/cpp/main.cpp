#include "FixedVector.hpp"
#include <iostream>

struct SensorData {
  int id;
  float temp;
};

int main() {
  std::cout << "=== 04 (Embedded Fixed) ===\n";

  // 1. Create a Vector with strict capacity of 5
  embedded::FixedVector<SensorData, 5> buffer;

  // 2. Fill it up
  for (int i = 0; i < 6; ++i) {
    bool success = buffer.push_back({i, 20.5f + i});
    if (success) {
      std::cout << "Logged Sensor " << i << ".\n";
    } else {
      std::cout << "[Warning] Buffer FULL! Dropping data " << i << ".\n";
    }
  }

  // 3. Process
  std::cout << "\nProcessing " << buffer.size() << " items:\n";
  for (const auto &sensor : buffer) {
    std::cout << " - ID: " << sensor.id << " Temp: " << sensor.temp << "\n";
  }

  return 0;
}
