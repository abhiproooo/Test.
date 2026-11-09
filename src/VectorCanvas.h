#ifndef VECTOR_CANVAS_H
#define VECTOR_CANVAS_H
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/input_event.hpp> // <--- ADDED THIS
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include "VectorPoint.h"
#include <vector>

class VectorCanvas : public godot::Node2D {
    GDCLASS(VectorCanvas, godot::Node2D)
private:
    std::vector<VectorPoint> points;
    godot::Vector2 pan_offset = godot::Vector2(0, 0);
    float zoom_factor = 1.0f;
protected:
    static void _bind_methods();
public:
    void add_point(const godot::Vector2 &p_point);
    void _draw() override;
    void _unhandled_input(const godot::Ref<godot::InputEvent> &p_event) override;
    VectorCanvas() {}
    ~VectorCanvas() {}
};
#endif
