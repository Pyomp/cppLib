#pragma once

#include <string>
#include <cstdint>

class StringBuffer : public std::string {
public:
    StringBuffer(std::string buffer) : std::string(buffer), _begin((void*)this->c_str()) {};
    StringBuffer(const size_t size) : std::string(size, '\0'), _begin((void*)this->c_str()) {};

    uint8_t getUint8(const size_t& offset) const;
    uint16_t getUint16(const size_t& offset) const;
    uint32_t getUint32(const size_t& offset) const;
    uint64_t getUint64(const size_t& offset) const;
    float getFloat32(const size_t& offset) const;

    size_t setUint8(const uint8_t& value, const size_t& offset);
    size_t setUint16(const uint16_t& value, const size_t& offset);
    size_t setUint32(const uint32_t& value, const size_t& offset);
    size_t setUint64(const uint64_t& value, const size_t& offset);
    size_t setInt64(const int64_t& value, const size_t& offset);
    size_t setFloat32(const float& value, const size_t& offset);
    size_t setString(const std::string& value, const size_t& offset);
private:
    void* _begin;
};
