#include <string>
#include <cstring>

#include "./stringBufferUtils.h"

uint8_t stringBufferUtils::getUint8(std::string str, size_t offset) {
    uint8_t a = str[offset];
    return a;
};

uint16_t stringBufferUtils::getUint16(std::string str, size_t offset) {
    uint16_t a = (str[offset] << 8) | str[offset + 1];
    return a;
}

uint32_t stringBufferUtils::getUint32(std::string str, size_t offset) {
    uint32_t a = (str[offset] << 24) | (str[offset + 1] << 16) | (str[offset + 2] << 8) | str[offset + 3];
    return a;
}

float stringBufferUtils::getFloat32(std::string str, size_t  offset) {
    float a;
    std::memcpy(&a, &str[offset], sizeof(float));
    return a;
}

std::string stringBufferUtils::getString(std::string str, size_t offset, size_t size) {
    return std::string(&str[offset], size);
};
