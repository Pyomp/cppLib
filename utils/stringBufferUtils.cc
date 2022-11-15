#include <string>
#include <cstring>

#include "./stringBufferUtils.h"

/* GETTERS */

uint8_t stringBufferUtils::getUint8(std::string str, size_t offset) {
    uint8_t a;
    std::memcpy(&a, &str[offset], sizeof(uint8_t));
    return a;
};

uint16_t stringBufferUtils::getUint16(std::string str, size_t offset) {
    uint16_t a;
    std::memcpy(&a, &str[offset], sizeof(uint16_t));
    return a;
}

uint32_t stringBufferUtils::getUint32(std::string str, size_t offset) {
    uint32_t a;
    std::memcpy(&a, &str[offset], sizeof(uint32_t));
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

std::string stringBufferUtils::getString(uint8_t value) {
    return std::string((char*)&value, sizeof(uint8_t));
};

std::string stringBufferUtils::getString(uint16_t value) {
    return std::string((char*)&value, sizeof(uint16_t));
};

std::string stringBufferUtils::getString(uint32_t value) {
    return std::string((char*)&value, sizeof(uint32_t));
};

std::string stringBufferUtils::getString(float value) {
    return std::string((char*)&value, sizeof(float));
};

/* SETTERS */

size_t setUint8(uint8_t value, std::string dest, size_t offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint8_t));
    return sizeof(uint8_t);
}

size_t setUint16(uint16_t value, std::string dest, size_t offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint16_t));
    return sizeof(uint16_t);
}

size_t setUint32(uint32_t value, std::string dest, size_t offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint32_t));
    return sizeof(uint32_t);
}

size_t setFloat32(float value, std::string dest, size_t offset) {
    std::memcpy(&dest[offset], &value, sizeof(float));
    return sizeof(float);
}

size_t setString(std::string value, std::string dest, size_t offset) {
    size_t size = value.size();
    std::memcpy(&dest[offset], &value, size);
    return size;
}
