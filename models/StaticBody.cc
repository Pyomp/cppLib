#include <string>

#include "./StaticBody.h"

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../libs/tiny_gltf.h"

StaticBody::StaticBody(std::string url) {
    tinygltf::Model model;
    tinygltf::TinyGLTF loader;
    std::string err;
    std::string warn;

    // bool ret = loader.LoadASCIIFromFile(&model, &err, &warn, "./terrain.glb");
    bool ret = loader.LoadBinaryFromFile(&model, &err, &warn, url); // for binary glTF(.glb)

    if (!warn.empty()) {
        printf("Warn: %s\n", warn.c_str());
    }

    if (!err.empty()) {
        printf("Err: %s\n", err.c_str());
    }

    if (!ret) {
        printf("Failed to parse glTF\n");
        return;
    }

    std::vector<Triangle> triangles;

    for (auto mesh : model.meshes) {
        if (mesh.name.starts_with("leafs")) continue;

        for (auto primitive : mesh.primitives) {
            auto positionIndex = primitive.attributes["POSITION"];
            auto normalIndex = primitive.attributes["NORMAL"];
            auto indicesIndex = primitive.indices;

            auto bufferViewPosition = model.bufferViews[model.accessors[positionIndex].bufferView];
            auto bufferViewNormal = model.bufferViews[model.accessors[normalIndex].bufferView];
            auto bufferViewIndices = model.bufferViews[model.accessors[indicesIndex].bufferView];

            auto bufferPosition = model.buffers[bufferViewPosition.buffer];
            float position[bufferViewPosition.byteLength / 4];
            memcpy(position, bufferPosition.data.data() + bufferViewPosition.byteOffset, bufferViewPosition.byteLength);

            auto bufferNormal = model.buffers[bufferViewNormal.buffer];
            float normal[bufferViewNormal.byteLength / 4];
            memcpy(normal, bufferNormal.data.data() + bufferViewNormal.byteOffset, bufferViewNormal.byteLength);

            auto bufferIndices = model.buffers[bufferViewIndices.buffer];
            size_t indicesLength = bufferViewIndices.byteLength / 2;
            uint16_t indices[indicesLength];
            memcpy(indices, bufferIndices.data.data() + bufferViewIndices.byteOffset, bufferViewIndices.byteLength);

            for (size_t i = 0; i < indicesLength; i += 3) {
                uint16_t aIndex = indices[i];
                uint16_t bIndex = indices[i + 1];
                uint16_t cIndex = indices[i + 2];

                Vector3 aVector(position[aIndex * 3], position[aIndex * 3 + 1], position[aIndex * 3 + 2]);
                Vector3 bVector(position[bIndex * 3], position[bIndex * 3 + 1], position[bIndex * 3 + 2]);
                Vector3 cVector(position[cIndex * 3], position[cIndex * 3 + 1], position[cIndex * 3 + 2]);

                Triangle triangle(aVector, bVector, cVector);

                this->triangles.push_back(triangle);

                Vector3 normal;
                triangle.getNormal(normal);
                this->normals.push_back(normal);

                this->resistances.push_back(
                    mesh.extras.Has("resistance") ? mesh.extras.Get("resistance").GetNumberAsDouble() : 1.01
                );

                Box3 boundingBox;
                triangle.getBoundingBox(boundingBox);
                this->boundingBoxes.push_back(boundingBox);
            }
            this->size = this->triangles.size();
        }
    };
};
