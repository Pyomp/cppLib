#include <string>
#include <cstring>

#include "./stringBufferUtils.h"

/* GETTERS */
uint8_t stringBufferUtils::getUint8(const std::string& str, const size_t& offset) {
    if (str.size() < sizeof(uint8_t) + offset)return 0;
    return *(uint8_t*)&str[offset];
};

uint16_t stringBufferUtils::getUint16(const std::string& str, const size_t& offset) {
    if (str.size() < sizeof(uint16_t) + offset)return 0;
    return *(uint16_t*)&str[offset];
}

uint32_t stringBufferUtils::getUint32(const std::string& str, const size_t& offset) {
    if (str.size() < sizeof(uint32_t) + offset)return 0;
    return *(uint32_t*)&str[offset];
}

float stringBufferUtils::getFloat32(const std::string& str, const size_t& offset) {
    if (str.size() < sizeof(float) + offset)return 0;
    return *(float*)&str[offset];
}

uint64_t stringBufferUtils::getUint64(const std::string& str, const size_t& offset) {
    if (str.size() < sizeof(uint64_t) + offset)return 0;
    return *(uint64_t*)&str[offset];
}

std::string stringBufferUtils::getString(const std::string& str, const size_t& offset, const size_t& size) {
    if (offset + size > str.size())return "";
    return std::string(&str[offset], size);
};

std::string stringBufferUtils::getString(const uint8_t& value) {
    return std::string((char*)&value, sizeof(uint8_t));
};

std::string stringBufferUtils::getString(const uint16_t& value) {
    return std::string((char*)&value, sizeof(uint16_t));
};

std::string stringBufferUtils::getString(const uint32_t& value) {
    return std::string((char*)&value, sizeof(uint32_t));
};

std::string stringBufferUtils::getString(const uint64_t& value) {
    return std::string((char*)&value, sizeof(uint64_t));
};

std::string stringBufferUtils::getString(const float& value) {
    return std::string((char*)&value, sizeof(float));
};

/* SETTERS */
size_t stringBufferUtils::setUint8(const uint8_t& value, std::string dest, const size_t& offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint8_t));
    return sizeof(uint8_t);
}

size_t stringBufferUtils::setUint16(const uint16_t& value, std::string dest, const size_t& offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint16_t));
    return sizeof(uint16_t);
}

size_t stringBufferUtils::setUint32(const uint32_t& value, std::string dest, const size_t& offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint32_t));
    return sizeof(uint32_t);
}

size_t stringBufferUtils::setUint64(const uint64_t& value, std::string dest, const size_t& offset) {
    std::memcpy(&dest[offset], &value, sizeof(uint64_t));
    return sizeof(uint64_t);
}

size_t stringBufferUtils::setFloat32(const float& value, std::string dest, const size_t& offset) {
    std::memcpy(&dest[offset], &value, sizeof(float));
    return sizeof(float);
}

size_t stringBufferUtils::setString(const std::string& value, std::string dest, const size_t& offset) {
    size_t size = value.size();
    std::memcpy(&dest[offset], &value, size);
    return size;
}
