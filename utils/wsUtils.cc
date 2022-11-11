#include "wsUtils.h"

uint16_t wsUtils::getCommand(std::string message) {
    if (message.size() < 2) return 0;
    return (message[0] << 8) + message[1];
};
