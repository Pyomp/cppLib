#pragma once

#include "Vector2.h"

#include <vector>

class Box2 {

public:
    Box2();

    Box2(const Vector2& min, const Vector2& max);

    Box2& set(const Vector2& min, const Vector2& max);

    Box2& setFromPoints(const std::vector<Vector2>& points);

    Box2& copy(const Box2& box);

    Box2& makeEmpty();

    [[nodiscard]] bool isEmpty() const;

    void getCenter(Vector2& target);

    void getSize(Vector2& target);

    Box2& expandByPoint(const Vector2& point);

    friend std::ostream& operator<<(std::ostream& os, const Box2& v) {
        os << "Box2(max=" << v.min_ << ", max=" << v.max_ << ")";
        return os;
    }

private:
    Vector2 min_;
    Vector2 max_;
};
