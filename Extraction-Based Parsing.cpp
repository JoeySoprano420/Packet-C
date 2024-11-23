#include <fstream>
#include <iostream>
#include <string>

class Extractor {
public:
    static std::string extract(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot open file: " + filename);

        std::string content, line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }
};

// Usage
std::string code = Extractor::extract("module.pc");
std::cout << code;
