#pragma once
#include <vector>
#include <thread>
#include <functional>

namespace valence {
namespace utils {

class ThreadPool {
public:
    ThreadPool(unsigned int numThreads = 0);
    ~ThreadPool();

    void enqueue(std::function<void()> task);
    // ...
};

} // namespace utils
} // namespace valence
