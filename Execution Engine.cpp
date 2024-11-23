#include <iostream>
#include <unordered_map>
#include <functional>

class ExecutionEngine {
public:
    void registerCapsule(const std::string &name, std::function<void()> func) {
        capsules[name] = func;
    }

    void executePacket(const std::string &packetName) {
        if (packets.find(packetName) == packets.end())
            throw std::runtime_error("Packet not found: " + packetName);

        for (const std::string &capsule : packets[packetName]) {
            if (capsules.find(capsule) != capsules.end()) {
                capsules[capsule]();
            } else {
                throw std::runtime_error("Capsule not found: " + capsule);
            }
        }
    }

    void definePacket(const std::string &name, const std::vector<std::string> &capsules) {
        packets[name] = capsules;
    }

private:
    std::unordered_map<std::string, std::function<void()>> capsules;
    std::unordered_map<std::string, std::vector<std::string>> packets;
};

// Example usage
ExecutionEngine engine;
engine.registerCapsule("Loader", []() { std::cout << "Loading resources...\n"; });
engine.registerCapsule("Processor", []() { std::cout << "Processing data...\n"; });

engine.definePacket("MainNode", {"Loader", "Processor"});
engine.executePacket("MainNode");
