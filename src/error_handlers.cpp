#include "error_handlers.h"

struct GlobalLogFile {
    std::fstream file;
    bool verbose = false;

    void close() {
        if (file.is_open()) {
            file.close();
        }
    }

    void open(const std::string& filename, bool verbose) {
        file.open(filename, std::ios::out);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open log file");
        }
        this->verbose = verbose;
    }
} global_log_file;

void openLogFile(const std::string& filename, bool verbose) {
    global_log_file.open(filename, verbose);
}

void closeLogFile() { global_log_file.close(); }

void handleLogMessage(
    const std::string& message, Severity severity, int exit_code, std::fstream& output) {
    switch (severity) {
        case Severity::INFO:
            output << "[INFO]: ";
            break;
        case Severity::WARNING:
            output << "[WARNING]: ";
            break;
        case Severity::ERROR:
            output << "[ERROR]: ";
            break;
        case Severity::CRITICAL:
            output << "[CRITICAL]: ";
            break;
    }

    output << message << std::endl;

    if (severity == Severity::CRITICAL) {
        exit(exit_code);
    }
}

void handleLogMessage(const std::string& message, Severity severity, int exit_code) {
    if (global_log_file.verbose || severity == Severity::CRITICAL || severity == Severity::ERROR) {
        handleLogMessage(message, severity, exit_code, global_log_file.file);
    }
}

void handleLogMessage(const std::string& message) {
    if (global_log_file.verbose) {
        handleLogMessage(message, Severity::INFO, 0, global_log_file.file);
    }
}
