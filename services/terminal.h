#pragma once

#include <map>
#include <string>
#include <iostream>
#include "stringUtils.h"

namespace terminal {

    std::map<std::string, void(*)(std::vector<std::string> args)> dispatcher;
    
    namespace {
        bool isInit = false;
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
    };

    void init(bool isThreaded) {
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
}