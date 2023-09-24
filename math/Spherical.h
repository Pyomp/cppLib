#pragma once
#include "./Vector3.h"
#include "./MathUtils.h"

class Spherical {

public:
    float radius;
    float phi;
    float theta;

    explicit Spherical(float radius = 1, float phi = 0, float theta = 0);

    Spherical& set(float radius, float phi, float theta);

    Spherical& copy(const Spherical& other);

    // restrict phi to be between EPS and PI-EPS
    Spherical& makeSafe();

    Spherical& setFromVector3(const Vector3& v);

    Spherical& setFromCartesianCoords(float x, float y, float z);
};
