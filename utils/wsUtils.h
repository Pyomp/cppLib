#pragma once

#include <cinttypes>
#include <string>

namespace wsUtils {
    uint16_t getCommand(std::string message);
    // std::string getCommand(uint16_t command);
    uint16_t getId(std::string message);
    // std::string getId(uint16_t command);
}