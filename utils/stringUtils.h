#pragma once

#include <vector>
#include <string>

namespace stringUtils {
    std::vector<std::string> split(std::string s, std::string delimiter);
    std::string stringToHex(const std::string& s);
}