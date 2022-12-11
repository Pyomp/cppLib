#pragma once

#include <vector>
#include <string>

#include "Triangle.h"
#include "Vector3.h"

class StaticBody {
public:
    StaticBody(std::string url);

    std::vector<Triangle> triangles;
    std::vector<Vector3> normals;
};