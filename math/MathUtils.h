#pragma once

#include <algorithm>
#include <cmath>

namespace mathUtils {

    const float LN2 = log(2.f);
    const float PI = 2.f * acos(0.f);
    const float PI05 = PI / 2;

    const float DEG2RAD = PI / 180.f;
    const float RAD2DEG = 180.f / PI;

    template<class T>
    T clamp(T value, T min, T max) {

        return max(min, min(max, value));
    }

    template<class T>
    void clamp(T& value, T min, T max) {

        value = max(min, min(max, value));
    }

    float mapLinear(float x, float a1, float a2, float b1, float b2);

    float inverseLerp(float x, float y, float value);

    float lerp(float x, float y, float t);

    float degToRad(float degrees);

    float radToDeg(float radians);

    float randomInRange(float min, float max);

    bool isPowerOfTwo(int value);

    float ceilPowerOfTwo(float value);

    float floorPowerOfTwo(float value);

    template <typename T>
    inline int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

    bool compareFloats(float f1, float f2);
}