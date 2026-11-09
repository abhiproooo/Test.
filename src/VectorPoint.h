#ifndef VECTOR_POINT_H
#define VECTOR_POINT_H

#include <godot_cpp/variant/vector2.hpp>

struct VectorPoint {
    godot::Vector2 position;
    bool is_selected = false;

    VectorPoint() {
        position = godot::Vector2(0, 0);
        is_selected = false;
    }
    
    VectorPoint(godot::Vector2 p_pos) {
        position = p_pos;
        is_selected = false;
    }
};

#endif
