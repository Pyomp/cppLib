#pragma once

#include <string>

namespace stringBufferUtils {
    uint8_t getUint8(const std::string& str, const size_t& offset);
    uint16_t getUint16(const std::string& str, const size_t& offset);
    uint32_t getUint32(const std::string& str, const size_t& offset);
    uint64_t getUint64(const std::string& str, const size_t& offset);
    float getFloat32(const std::string& str, const size_t& offset);
    std::string getString(const std::string& str, const size_t& offset, const  size_t& size);

    std::string getString(const uint8_t& value);
    std::string getString(const uint16_t& value);
    std::string getString(const uint32_t& value);
    std::string getString(const uint64_t& value);
    std::string getString(const float& value);

    size_t setUint8(const uint8_t& value, std::string dest, const size_t& offset);
    size_t setUint16(const uint16_t& value, std::string dest, const size_t& offset);
    size_t setUint32(const uint32_t& value, std::string dest, const size_t& offset);
    size_t setUint64(const uint64_t& value, std::string dest, const size_t& offset);
    size_t setFloat32(const float& value, std::string dest, const size_t& offset);
    size_t setString(const std::string& value, std::string dest, const size_t& offset);
}
