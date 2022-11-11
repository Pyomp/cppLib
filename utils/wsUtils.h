#pragma once

#include <cinttypes>
#include <string>

namespace wsUtils {
    uint16_t getCommand(std::string message);
    std::string getCommand(uint16_t command);
}