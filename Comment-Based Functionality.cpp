#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>

class CommentProcessor {
public:
    void registerCommand(const std::string &command, std::function<void()> func) {
        commands[command] = func;
    }

    void processComment(const std::string &comment) {
        if (commands.find(comment) != commands.end()) {
            commands[comment]();
        } else {
            std::cerr << "Unrecognized comment command: " << comment << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::function<void()>> commands;
};

// Usage
CommentProcessor processor;
processor.registerCommand("#init", []() { std::cout << "Initializing...\n"; });
processor.registerCommand("#shutdown", []() { std::cout << "Shutting down...\n"; });

processor.processComment("#init");
processor.processComment("#shutdown");
