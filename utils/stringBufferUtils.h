#pragma once

#include <string>

namespace stringBufferUtils {
    uint8_t getUint8(std::string str, size_t offset);
    uint16_t getUint16(std::string str, size_t offset);
    uint32_t getUint32(std::string str, size_t offset);
    uint64_t getUint64(std::string str, size_t offset);
    float getFloat32(std::string str, size_t offset);
    std::string getString(std::string str, size_t offset, size_t size);

    std::string getString(uint8_t value);
    std::string getString(uint16_t value);
    std::string getString(uint32_t value);
    std::string getString(uint64_t value);
    std::string getString(float value);

    size_t setUint8(uint8_t value, std::string dest, size_t offset);
    size_t setUint16(uint16_t value, std::string dest, size_t offset);
    size_t setUint32(uint32_t value, std::string dest, size_t offset);
    size_t setUint64(uint64_t value, std::string dest, size_t offset);
    size_t setFloat32(float value, std::string dest, size_t offset);
    size_t setString(std::string value, std::string dest, size_t offset);
}