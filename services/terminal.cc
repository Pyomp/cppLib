#include "terminal.h"

#include <map>
#include <string>
#include <iostream>
#include <functional>
#include <thread>

#include "../utils/stringUtils.h"

namespace {
    std::unordered_map<std::string, TerminalCallback> dispatcher;
    bool isInit = false;
}

void loop() {
    while (1) {
        std::cout << "$ ";
        std::string command;
        std::cin >> command;
        if (command == "exit") return;
        auto args = stringUtils::split(command, " ");
        if (dispatcher.contains(args[0])) {
            dispatcher[args[0]](args);
        }
        else {
            std::cout << "Command unknown: " << args[0];
        }
        std::cout << std::endl;
    }
}

void terminal::addCallback(std::string command, TerminalCallback callback) {
    if (dispatcher.contains(command)) throw "Command: '" + command + "' already used.";
    dispatcher[command] = callback;
}

void terminal::init(bool isThreaded) {
    if (isInit)return;
    isInit = true;

    dispatcher["ping"] = [](std::vector<std::string> args) {
        std::cout << "pong";
        };

    if (isThreaded) {
        std::thread one(loop);
        one.detach();
    }
    else {
        loop();
    }
};
