#pragma once

#include "Plane.h"

#include <array>

class Box3;
class Sphere;
class Object3D;

class Frustum {

public:
    explicit Frustum(Plane p0 = Plane(), Plane p1 = Plane(), Plane p2 = Plane(), Plane p3 = Plane(), Plane p4 = Plane(), Plane p5 = Plane());

    Frustum& set(const Plane& p0, const Plane& p1, const Plane& p2, const Plane& p3, const Plane& p4, const Plane& p5);

    Frustum& copy(const Frustum& frustum);

    Frustum& setFromProjectionMatrix(const Matrix4& m);

    bool intersectsSphere(const Sphere& sphere);

    bool intersectsBox(const Box3& box);

    bool containsPoint(const Vector3& point);


private:
    std::array<Plane, 6> planes_;
};
