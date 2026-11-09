#ifndef VECTOR_POINT_H
#define VECTOR_POINT_H
#include <godot_cpp/variant/vector2.hpp>

struct VectorPoint {
    godot::Vector2 position;
    VectorPoint() : position(0, 0) {}
    VectorPoint(godot::Vector2 p_pos) : position(p_pos) {}
};
#endif
