#pragma once

#include <string>
#include <functional>

typedef std::function<void(std::vector<std::string>)> TerminalCallback;

namespace terminal {
    void addCallback(std::string command, TerminalCallback callback);
    void init(bool isThreaded);
}