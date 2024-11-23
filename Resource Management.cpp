#include <queue>
#include <mutex>

class ResourcePool {
public:
    ResourcePool(int size) {
        for (int i = 0; i < size; ++i) pool.push(new char[1024]); // 1KB blocks
    }

    ~ResourcePool() {
        while (!pool.empty()) {
            delete[] pool.front();
            pool.pop();
        }
    }

    void *acquire() {
        std::lock_guard<std::mutex> lock(poolMutex);
        if (pool.empty()) return nullptr;
        void *resource = pool.front();
        pool.pop();
        return resource;
    }

    void release(void *resource) {
        std::lock_guard<std::mutex> lock(poolMutex);
        pool.push(resource);
    }

private:
    std::queue<void *> pool;
    std::mutex poolMutex;
};

// Usage
ResourcePool pool(10);
void *block = pool.acquire();
// Use resource...
pool.release(block);
