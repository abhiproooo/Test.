#ifndef VECTOR_CANVAS_H
#define VECTOR_CANVAS_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include "VectorPoint.h"
#include <vector>
#include <map>

class VectorCanvas : public godot::Node2D {
    GDCLASS(VectorCanvas, godot::Node2D)

private:
    std::vector<VectorPoint> points;
    int active_tool = 0;
    std::map<int, godot::Vector2> active_touches;

protected:
    static void _bind_methods();

public:
    void set_tool(int p_tool);
    void add_point(const godot::Vector2 &p_point);
    void _draw() override;
    void _unhandled_input(const godot::Ref<godot::InputEvent> &p_event) override;
    
    VectorCanvas() {}
    ~VectorCanvas() {}
};

#endif
