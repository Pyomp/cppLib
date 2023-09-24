#pragma once

#include "./Plane.h"
#include "./Sphere.h"
#include "./Triangle.h"
#include "./Vector3.h"
#include "./infinity.h"

class Box3 {

public:
    Vector3 min;
    Vector3 max;

    Box3();

    Box3(Vector3 min, Vector3 max);

    Box3& set(const Vector3& min, const Vector3& max);

    Box3& set(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    template<class ArrayLike>
    Box3& setFromArray(const ArrayLike& array) {

        const auto minX = +Infinity<float>;
        const auto minY = +Infinity<float>;
        const auto minZ = +Infinity<float>;

        const auto maxX = -Infinity<float>;
        const auto maxY = -Infinity<float>;
        const auto maxZ = -Infinity<float>;

        for (int i = 0, l = array.size(); i < l; i += 3) {

            const auto x = array[i];
            const auto y = array[i + 1];
            const auto z = array[i + 2];

            if (x < minX) minX = x;
            if (y < minY) minY = y;
            if (z < minZ) minZ = z;

            if (x > maxX) maxX = x;
            if (y > maxY) maxY = y;
            if (z > maxZ) maxZ = z;
        }

        this->min.set(minX, minY, minZ);
        this->max.set(maxX, maxY, maxZ);

        return *this;
    }

    template<class ArrayLike>
    Box3& setFromPoints(const ArrayLike& points) {

        this->makeEmpty();

        for (const auto& point : points) {

            this->expandByPoint(point);
        }

        return *this;
    }

    Box3& setFromCenterAndSize(const Vector3& center, const Vector3& size);

    Box3& copy(const Box3& box);

    Box3& makeEmpty();

    [[nodiscard]] bool isEmpty() const;

    void getCenter(Vector3& target) const;

    void getSize(Vector3& target) const;

    Box3& expandByPoint(const Vector3& point);

    Box3& expandByVector(const Vector3& vector);

    Box3& expandByScalar(float scalar);

    [[nodiscard]] bool containsPoint(const Vector3& point) const;

    [[nodiscard]] bool containsBox(const Box3& box) const;

    void getParameter(const Vector3& point, Vector3& target) const;

    [[nodiscard]] bool intersectsBox(const Box3& box) const;

    [[nodiscard]] bool intersectsSphere(const Sphere& sphere) const;

    [[nodiscard]] bool intersectsPlane(const Plane& plane) const;

    [[nodiscard]] bool intersectsTriangle(const Triangle& triangle) const;

    Vector3& clampPoint(const Vector3& point, Vector3& target) const;

    [[nodiscard]] float distanceToPoint(const Vector3& point) const;

    void getBoundingSphere(Sphere& target) const;

    Box3& intersect(const Box3& box);

    Box3& union_(const Box3& box);

    Box3& applyMatrix4(const Matrix4& matrix);

    Box3& translate(const Vector3& offset);

    friend std::ostream& operator<<(std::ostream& os, const Box3& v) {
        os << "Box3(max=" << v.min << ", max=" << v.max << ")";
        return os;
    }


private:

    static bool satForAxes(const std::vector<float>& axes, const Vector3& v0, const Vector3& v1, const Vector3& v2, const Vector3& extents);
};
