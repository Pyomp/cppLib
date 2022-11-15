#include "wsUtils.h"

uint16_t wsUtils::getCommand(std::string message) {
    if (message.size() < 2) return 0;
    return  message[0] + (message[1] << 8);
};

std::string wsUtils::getCommand(uint16_t command) {
    return std::string((char*)&command, sizeof(uint16_t));
};

uint16_t wsUtils::getId(std::string message) {
    if (message.size() < 4) return 0;
    return  message[2] + (message[3] << 8);
};

std::string wsUtils::getId(uint16_t id) {
    return std::string((char*)&id, sizeof(uint16_t));
};