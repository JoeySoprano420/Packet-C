#include <unordered_set>
#include <mutex>

class GarbageCollector {
public:
    void addObject(void *object) {
        std::lock_guard<std::mutex> lock(gcMutex);
        objects.insert(object);
    }

    void removeObject(void *object) {
        std::lock_guard<std::mutex> lock(gcMutex);
        objects.erase(object);
    }

    void collect() {
        std::lock_guard<std::mutex> lock(gcMutex);
        for (void *obj : objects) {
            delete static_cast<char *>(obj); // Adjust for custom object types
        }
        objects.clear();
    }

private:
    std::unordered_set<void *> objects;
    std::mutex gcMutex;
};

// Usage
GarbageCollector gc;
void *temp = new char[128]; // Sample allocation
gc.addObject(temp);
gc.collect();
