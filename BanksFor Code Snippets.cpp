#include <unordered_map>
#include <string>
#include <iostream>

class CodeBank {
public:
    void addSnippet(const std::string &name, const std::string &code) {
        snippets[name] = code;
    }

    std::string getSnippet(const std::string &name) {
        return snippets.count(name) ? snippets[name] : "Snippet not found.";
    }

    void listSnippets() {
        for (const auto &[name, code] : snippets) {
            std::cout << "Snippet [" << name << "]: " << code.substr(0, 30) << "...\n";
        }
    }

private:
    std::unordered_map<std::string, std::string> snippets;
};

// Usage
CodeBank bank;
bank.addSnippet("Initialize", "capsule Init { /* Initialization Code */ }");
bank.listSnippets();
