#pragma once

#include <string>

namespace stringBufferUtils {
    uint8_t getUint8(std::string str, size_t offset);
    uint16_t getUint16(std::string str, size_t offset);
    uint32_t getUint32(std::string str, size_t offset);
    float getFloat32(std::string str, size_t offset);
    std::string getString(std::string str, size_t offset, size_t size);
}