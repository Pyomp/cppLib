#pragma once

#include <vector>
#include <string>

#include "Triangle.h"
#include "Box3.h"
#include "Vector3.h"

class StaticBody {
public:
    StaticBody(std::string url);

    std::vector<Triangle> triangles;
    std::vector<Box3> boundingBoxes;
    std::vector<Vector3> normals;
    std::vector<float> resistances;
    size_t size;
};
