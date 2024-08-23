#include <cstring> // memcpy

#include "StringBuffer.h"

uint8_t StringBuffer::getUint8(const size_t& offset) const {
    if (this->size() < sizeof(uint8_t) + offset) return 0;
    return *(uint8_t*)(this->_begin + offset);
};

uint16_t StringBuffer::getUint16(const size_t& offset) const {
    if (this->size() < sizeof(uint16_t) + offset) return 0;
    return *(uint16_t*)(this->_begin + offset);
}

uint32_t StringBuffer::getUint32(const size_t& offset)const {
    if (this->size() < sizeof(uint32_t) + offset) return 0;
    return *(uint32_t*)(this->_begin + offset);
}

float StringBuffer::getFloat32(const size_t&  offset) const {
    if (this->size() < sizeof(float) + offset) return 0;
    return *(float*)(this->_begin + offset);
}

uint64_t StringBuffer::getUint64(const size_t& offset)const {
    if (this->size() < sizeof(uint64_t) + offset) return 0;
    return *(uint64_t*)(this->_begin + offset);
}

size_t StringBuffer::setUint8(const uint8_t& value, const size_t& offset) {
    if (this->size() < sizeof(uint8_t) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(uint8_t));
    return sizeof(uint8_t);
}

size_t StringBuffer::setUint16(const uint16_t& value, const size_t& offset) {
    if (this->size() < sizeof(uint16_t) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(uint16_t));
    return sizeof(uint16_t);
}

size_t StringBuffer::setUint32(const uint32_t& value, const size_t& offset) {
    if (this->size() < sizeof(uint32_t) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(uint32_t));
    return sizeof(uint32_t);
}

size_t StringBuffer::setUint64(const uint64_t& value, const size_t& offset) {
    if (this->size() < sizeof(uint64_t) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(uint64_t));
    return sizeof(uint64_t);
}

size_t StringBuffer::setInt64(const int64_t& value, const size_t& offset) {
    if (this->size() < sizeof(int64_t) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(int64_t));
    return sizeof(int64_t);
}

size_t StringBuffer::setFloat32(const float &value, const size_t &offset) {
    if (this->size() < sizeof(value) + offset) return 0;
    std::memcpy(this->_begin + offset, &value, sizeof(float));
    return sizeof(float);
}

size_t StringBuffer::setString(const std::string& value, const size_t& offset) {
    size_t size = value.size();
    if (this->size() < size + offset) return 0;
    std::memcpy(this->_begin + offset, &value, size);
    return size;
}
