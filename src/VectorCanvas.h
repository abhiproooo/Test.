#ifndef VECTOR_POINT_H
#define VECTOR_POINT_H

#include <godot_cpp/variant/vector2.hpp>

struct VectorPoint {
    godot::Vector2 position;
    bool is_selected = false; // <--- THIS IS THE MISSING LINE!

    VectorPoint() {}
    VectorPoint(godot::Vector2 p_pos) {
        position = p_pos;
        is_selected = false;
    }
};

#endif
