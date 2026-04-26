#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "./MathUtils.h"

class Matrix3;
class Matrix4;
class Spherical;
class Quaternion;
class Camera;

class Vector3 {

public:
    float x{ 0.f };
    float y{ 0.f };
    float z{ 0.f };

    Vector3() = default;

    Vector3(float x, float y, float z);

    inline Vector3& set(float x, float y, float z) {

        this->x = x;
        this->y = y;
        this->z = z;

        return *this;
    }

    inline Vector3& setScalar(float value) {

        this->x = value;
        this->y = value;
        this->z = value;

        return *this;
    }

    Vector3& setX(float value) {

        this->x = value;

        return *this;
    }

    Vector3& setY(float value) {

        y = value;

        return *this;
    }

    Vector3& setZ(float value) {

        z = value;

        return *this;
    }

    float& operator[](unsigned int index) {
        switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::runtime_error("index out of bound: " + std::to_string(index));
        }
    }

    Vector3& copy(const Vector3& v) {

        this->x = v.x;
        this->y = v.y;
        this->z = v.z;

        return *this;
    }

    Vector3& add(const Vector3& v) {

        this->x += v.x;
        this->y += v.y;
        this->z += v.z;

        return *this;
    }

    Vector3& addScalar(float s) {

        this->x += s;
        this->y += s;
        this->z += s;

        return *this;
    }

    Vector3& addVectors(const Vector3& a, const Vector3& b) {

        this->x = a.x + b.x;
        this->y = a.y + b.y;
        this->z = a.z + b.z;

        return *this;
    }

    Vector3& addScaledVector(const Vector3& v, float s) {

        this->x += v.x * s;
        this->y += v.y * s;
        this->z += v.z * s;

        return *this;
    }

    Vector3& sub(const Vector3& v) {

        this->x -= v.x;
        this->y -= v.y;
        this->z -= v.z;

        return *this;
    }

    Vector3& subScalar(float s) {

        this->x -= s;
        this->y -= s;
        this->z -= s;

        return *this;
    }

    Vector3& subVectors(const Vector3& a, const Vector3& b) {

        this->x = a.x - b.x;
        this->y = a.y - b.y;
        this->z = a.z - b.z;

        return *this;
    }

    Vector3& multiply(const Vector3& v) {

        this->x *= v.x;
        this->y *= v.y;
        this->z *= v.z;

        return *this;
    }

    Vector3& multiplyScalar(float scalar) {

        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }

    Vector3& multiplyVectors(const Vector3& a, const Vector3& b) {

        this->x = a.x * b.x;
        this->y = a.y * b.y;
        this->z = a.z * b.z;

        return *this;
    }

    Vector3& applyMatrix3(const Matrix3& m);

    Vector3& applyNormalMatrix(const Matrix3& m);

    Vector3& applyMatrix4(const Matrix4& m);

    Vector3& applyQuaternion(const Quaternion& q);

    Vector3& transformDirection(const Matrix4& m);

    Vector3& divide(const Vector3& v) {
        this->x /= v.x;
        this->y /= v.y;
        this->z /= v.z;

        return *this;
    }

    Vector3& divideScalar(const float& v) {
        this->x /= v;
        this->y /= v;
        this->z /= v;

        return *this;
    }

    Vector3& min(const Vector3& v) {

        this->x = std::min(this->x, v.x);
        this->y = std::min(this->y, v.y);
        this->z = std::min(this->z, v.z);

        return *this;
    }

    Vector3& max(const Vector3& v) {

        this->x = std::max(this->x, v.x);
        this->y = std::max(this->y, v.y);
        this->z = std::max(this->z, v.z);

        return *this;
    }

    Vector3& clamp(const Vector3& min, const Vector3& max) {

        // assumes min < max, componentwise

        this->x = std::max(min.x, std::min(max.x, this->x));
        this->y = std::max(min.y, std::min(max.y, this->y));
        this->z = std::max(min.z, std::min(max.z, this->z));

        return *this;
    }

    Vector3& floor() {

        this->x = std::floor(this->x);
        this->y = std::floor(this->y);
        this->z = std::floor(this->z);

        return *this;
    }

    Vector3& ceil() {

        this->x = std::ceil(this->x);
        this->y = std::ceil(this->y);
        this->z = std::ceil(this->z);

        return *this;
    }

    Vector3& round() {

        this->x = std::round(this->x);
        this->y = std::round(this->y);
        this->z = std::round(this->z);

        return *this;
    }

    Vector3& roundToZero() {

        this->x = (x < 0) ? std::ceil(this->x) : std::floor(this->x);
        this->y = (y < 0) ? std::ceil(this->y) : std::floor(this->y);
        this->z = (z < 0) ? std::ceil(this->z) : std::floor(this->z);

        return *this;
    }

    Vector3& negate() {

        x = -x;
        y = -y;
        z = -z;

        return *this;
    }

    [[nodiscard]] inline float dot(const Vector3& v) const {

        return x * v.x + y * v.y + z * v.z;
    }

    [[nodiscard]] float lengthSq() const {

        return x * x + y * y + z * z;
    }

    [[nodiscard]] float length() const {

        return std::sqrt(x * x + y * y + z * z);
    }

    [[nodiscard]] float manhattanLength() const {

        return std::abs(x) + std::abs(y) + std::abs(z);
    }

    Vector3& normalize() {

        auto l = length();
        if (!std::isnan(l)) {
            if (l == 0) {
                this->multiplyScalar(0);
            }
            else {
                this->divideScalar(l);
            }
        }

        return *this;
    }

    Vector3& setLength(float length) {

        return normalize().multiplyScalar(length);
    }

    Vector3& lerp(const Vector3& v, float alpha) {

        this->x += (v.x - x) * alpha;
        this->y += (v.y - y) * alpha;
        this->z += (v.z - z) * alpha;

        return *this;
    }

    Vector3& lerpVectors(const Vector3& v1, const Vector3& v2, float alpha) {

        this->x = v1.x + (v2.x - v1.x) * alpha;
        this->y = v1.y + (v2.y - v1.y) * alpha;
        this->z = v1.z + (v2.z - v1.z) * alpha;

        return *this;
    }

    Vector3& cross(const Vector3& v) {

        return crossVectors(*this, v);
    }

    Vector3& crossVectors(const Vector3& a, const Vector3& b) {

        const auto ax = a.x, ay = a.y, az = a.z;
        const auto bx = b.x, by = b.y, bz = b.z;

        this->x = ay * bz - az * by;
        this->y = az * bx - ax * bz;
        this->z = ax * by - ay * bx;

        return *this;
    }

    Vector3& projectOnVector(const Vector3& v) {

        const auto denominator = v.lengthSq();

        if (denominator == 0) return this->set(0, 0, 0);

        const auto scalar = v.dot(*this) / denominator;

        return this->copy(v).multiplyScalar(scalar);
    }

    Vector3& projectOnPlane(const Vector3& planeNormal) {

        Vector3 _vector;
        _vector.copy(*this).projectOnVector(planeNormal);

        return this->sub(_vector);
    }

    Vector3& reflect(const Vector3& normal) {

        // reflect incident vector off plane orthogonal to normal
        // normal is assumed to have unit length

        Vector3 _vector;
        return this->sub(_vector.copy(normal).multiplyScalar(2 * this->dot(normal)));
    }

    [[nodiscard]] float angleTo(const Vector3& v) const {

        const auto denominator = std::sqrt(lengthSq() * v.lengthSq());

        if (denominator == 0) return mathUtils::PI / 2;

        const auto theta = dot(v) / denominator;

        // clamp, to handle numerical problems

        return std::acos(std::clamp(theta, -1.0f, 1.0f));
    }

    [[nodiscard]] float distanceTo(const Vector3& v) const {

        return std::sqrt(distanceToSquared(v));
    }

    [[nodiscard]] float distanceToSquared(const Vector3& v) const {

        const auto dx = this->x - v.x, dy = this->y - v.y, dz = this->z - v.z;

        return dx * dx + dy * dy + dz * dz;
    }

    [[nodiscard]] float manhattanDistanceTo(const Vector3& v) const {

        return std::abs(this->x - v.x) + std::abs(this->y - v.y) + std::abs(this->z - v.z);
    }

    Vector3& setFromSpherical(const Spherical& s);

    Vector3& setFromSphericalCoords(float radius, float phi, float theta);

    Vector3& setFromMatrixPosition(const Matrix4& m);

    Vector3& setFromMatrixScale(const Matrix4& m);

    Vector3& setFromMatrixColumn(const Matrix4& m, unsigned int index);

    Vector3& setFromMatrix3Column(const Matrix3& m, unsigned int index);


    [[nodiscard]] Vector3 clone() const {

        return Vector3{ x,y,z };
    }

    [[nodiscard]] bool equals(const Vector3& v) const {

        return ((v.x == this->x) && (v.y == this->y) && (v.z == this->z));
    }

    inline bool operator==(const Vector3& other) const {
        return equals(other);
    }

    inline bool operator!=(const Vector3& other) const {
        return !equals(other);
    }

    template<class ArrayLike>
    inline Vector3& fromArray(const ArrayLike& array, unsigned int offset = 0) {

        this->x = array[offset];
        this->y = array[offset + 1];
        this->z = array[offset + 2];

        return *this;
    }

    template<class ArrayLike>
    inline void toArray(ArrayLike& array, unsigned int offset = 0) const {

        array[offset] = this->x;
        array[offset + 1] = this->y;
        array[offset + 2] = this->z;
    }

    inline std::string toJson()const noexcept {
        std::stringstream s;
        s << "{\"x\":" << x << ",\"y\":" << y << ",\"z\":" << z << "}";
        return s.str();
    }

    static const Vector3 X;
    static const Vector3 Y;
    static const Vector3 Z;

    static const Vector3 ONES;
    static const Vector3 ZEROS;

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "{\"x\":" << v.x << ",\"y\":" << v.y << ",\"z\":" << v.z << "}";
        return os;
    }
};
