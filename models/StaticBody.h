#pragma once

#include <vector>
#include <string>

#include "../math/Triangle.h"
#include "../math/Box3.h"
#include "../math/Vector3.h"

class StaticBody {
public:
    StaticBody(std::string url);

    std::vector<Triangle> triangles;
    std::vector<Box3> boundingBoxes;
    std::vector<Vector3> normals;
    std::vector<float> resistances;
    size_t size;
};
