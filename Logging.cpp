#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    static void init(const std::string &filename) {
        logfile.open(filename, std::ios::out | std::ios::app);
        if (!logfile.is_open()) throw std::runtime_error("Failed to open log file.");
    }

    static void log(const std::string &message) {
        std::cout << "[LOG]: " << message << std::endl;
        if (logfile.is_open()) logfile << "[LOG]: " << message << "\n";
    }

    static void close() {
        if (logfile.is_open()) logfile.close();
    }

private:
    static inline std::ofstream logfile;
};

// Usage
Logger::init("runtime.log");
Logger::log("Starting execution...");
Logger::close();
