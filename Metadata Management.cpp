#include <unordered_map>
#include <string>
#include <iostream>

class MetadataManager {
public:
    void addMetadata(const std::string &key, const std::string &value) {
        metadata[key] = value;
    }

    std::string getMetadata(const std::string &key) {
        return metadata.count(key) ? metadata[key] : "Key not found.";
    }

    void displayAllMetadata() {
        for (const auto &[key, value] : metadata) {
            std::cout << key << ": " << value << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::string> metadata;
};

// Usage
MetadataManager manager;
manager.addMetadata("Version", "1.0.0");
manager.addMetadata("Author", "PacketC Dev Team");
manager.displayAllMetadata();
