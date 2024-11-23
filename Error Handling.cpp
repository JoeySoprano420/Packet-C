#include <iostream>
#include <exception>
#include <string>
#include <unordered_map>

class PacketCError : public std::exception {
public:
    PacketCError(const std::string &message) : message(message) {}
    const char *what() const noexcept override { return message.c_str(); }

private:
    std::string message;
};

class ErrorHandler {
public:
    static void registerError(int code, const std::string &description) {
        errorMap[code] = description;
    }

    static void throwError(int code) {
        if (errorMap.find(code) != errorMap.end()) {
            throw PacketCError("Error [" + std::to_string(code) + "]: " + errorMap[code]);
        } else {
            throw PacketCError("Unknown error code: " + std::to_string(code));
        }
    }

    static void logError(const std::exception &e) { std::cerr << e.what() << std::endl; }

private:
    static inline std::unordered_map<int, std::string> errorMap;
};

// Usage
ErrorHandler::registerError(100, "Capsule missing.");
ErrorHandler::registerError(101, "Packet execution failed.");

try {
    ErrorHandler::throwError(100);
} catch (const std::exception &e) {
    ErrorHandler::logError(e);
}
