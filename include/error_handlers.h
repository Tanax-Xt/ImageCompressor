#pragma once

#include <fstream>
#include <colors.h>

extern struct GlobalLogFile global_log_file;

void openLogFile(const std::string& filename, bool verbose = false);
void closeLogFile();

enum class Severity { INFO, WARNING, ERROR, CRITICAL };

void handleLogMessage(
    const std::string& message, Severity severity, int exit_code, std::fstream& output);

void handleLogMessage(
    const std::string& message, Severity severity = Severity::INFO, int exit_code = 0);

void handleLogMessage(const std::string& message);
