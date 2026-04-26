#include "./Vector3.h"
#include "./Matrix3.h"
#include "./Matrix4.h"
#include "./Quaternion.h"
#include "./Spherical.h"
#include "./MathUtils.h"

#include <algorithm>
#include <cmath>
#include <stdexcept>

const Vector3 Vector3::X = Vector3{ 1, 0, 0 };
const Vector3 Vector3::Y = Vector3{ 0, 1, 0 };
const Vector3 Vector3::Z = Vector3{ 0, 0, 1 };

const Vector3 Vector3::ONES = Vector3{ 1, 1, 1 };
const Vector3 Vector3::ZEROS = Vector3{ 0, 0, 0 };

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3& Vector3::applyMatrix3(const Matrix3& m) {

    const auto x_ = this->x, y_ = this->y, z_ = this->z;
    const auto& e = m.elements;

    this->x = e[0] * x_ + e[3] * y_ + e[6] * z_;
    this->y = e[1] * x_ + e[4] * y_ + e[7] * z_;
    this->z = e[2] * x_ + e[5] * y_ + e[8] * z_;

    return *this;
}

Vector3& Vector3::applyNormalMatrix(const Matrix3& m) {

    return applyMatrix3(m).normalize();
}

Vector3& Vector3::applyMatrix4(const Matrix4& m) {

    const auto x_ = this->x, y_ = this->y, z_ = this->z;
    const auto& e = m.elements;

    const auto w = 1.0f / (e[3] * x + e[7] * y + e[11] * z + e[15]);

    this->x = (e[0] * x_ + e[4] * y_ + e[8] * z_ + e[12]) * w;
    this->y = (e[1] * x_ + e[5] * y_ + e[9] * z_ + e[13]) * w;
    this->z = (e[2] * x_ + e[6] * y_ + e[10] * z_ + e[14]) * w;

    return *this;
}

Vector3& Vector3::applyQuaternion(const Quaternion& q) {

    const auto x = this->x, y = this->y, z = this->z;
    const auto qx = q.x(), qy = q.y(), qz = q.z(), qw = q.w();

    // calculate quat * vector

    const auto ix = qw * x + qy * z - qz * y;
    const auto iy = qw * y + qz * x - qx * z;
    const auto iz = qw * z + qx * y - qy * x;
    const auto iw = -qx * x - qy * y - qz * z;

    // calculate result * inverse quat

    this->x = ix * qw + iw * -qx + iy * -qz - iz * -qy;
    this->y = iy * qw + iw * -qy + iz * -qx - ix * -qz;
    this->z = iz * qw + iw * -qz + ix * -qy - iy * -qx;

    return *this;
}

Vector3& Vector3::transformDirection(const Matrix4& m) {

    // input: THREE.Matrix4 affine matrix
    // vector interpreted as a direction

    const auto x = this->x, y = this->y, z = this->z;
    const auto& e = m.elements;

    this->x = e[0] * x + e[4] * y + e[8] * z;
    this->y = e[1] * x + e[5] * y + e[9] * z;
    this->z = e[2] * x + e[6] * y + e[10] * z;

    return this->normalize();
}

Vector3& Vector3::setFromSpherical(const Spherical& s) {

    return this->setFromSphericalCoords(s.radius, s.phi, s.theta);
}

Vector3& Vector3::setFromSphericalCoords(float radius, float phi, float theta) {

    const auto sinPhiRadius = std::sin(phi) * radius;

    this->x = sinPhiRadius * std::sin(theta);
    this->y = std::cos(phi) * radius;
    this->z = sinPhiRadius * std::cos(theta);

    return *this;
}

Vector3& Vector3::setFromMatrixPosition(const Matrix4& m) {

    const auto& e = m.elements;

    this->x = e[12];
    this->y = e[13];
    this->z = e[14];

    return *this;
}

Vector3& Vector3::setFromMatrixScale(const Matrix4& m) {

    const auto sx = this->setFromMatrixColumn(m, 0).length();
    const auto sy = this->setFromMatrixColumn(m, 1).length();
    const auto sz = this->setFromMatrixColumn(m, 2).length();

    this->x = sx;
    this->y = sy;
    this->z = sz;

    return *this;
}

Vector3& Vector3::setFromMatrixColumn(const Matrix4& m, unsigned int index) {

    return this->fromArray(m.elements, index * 4);
}

Vector3& Vector3::setFromMatrix3Column(const Matrix3& m, unsigned int index) {

    return this->fromArray(m.elements, index * 3);
}
