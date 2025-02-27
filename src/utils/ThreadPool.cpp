#include "utils/ThreadPool.hpp"

namespace valence {
namespace utils {

ThreadPool::ThreadPool(unsigned int numThreads) {
    // TODO: Initialize threads
}

ThreadPool::~ThreadPool() {
    // TODO: Join threads
}

void ThreadPool::enqueue(std::function<void()> task) {
    // TODO: Add tasks to queue
}

} // namespace utils
} // namespace valence
