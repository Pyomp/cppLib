#include "wsUtils.h"

uint16_t wsUtils::getCommand(std::string message) {
    if (message.size() < 2) return 0;
    return  message[0] + (message[1] << 8);
};

std::string wsUtils::getCommand(uint16_t command) {
    return std::string((char*)&command, sizeof(uint16_t));
};
