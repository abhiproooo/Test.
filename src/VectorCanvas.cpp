#include "VectorCanvas.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_screen_touch.hpp>
#include <godot_cpp/classes/viewport.hpp>

using namespace godot;

void VectorCanvas::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add_point", "point"), &VectorCanvas::add_point);
}

void VectorCanvas::add_point(const Vector2 &p_point) {
    points.push_back(VectorPoint(p_point));
    queue_redraw();
}

void VectorCanvas::_unhandled_input(const Ref<InputEvent> &p_event) {
    Ref<InputEventScreenTouch> touch = p_event;
    if (touch.is_valid() && touch->is_pressed()) {
        // Get the exact touch position on the screen
        Vector2 local_pos = touch->get_position(); 
        add_point(local_pos);
        get_viewport()->set_input_as_handled();
    }
}

void VectorCanvas::_draw() {
    if (points.size() < 2) return;
    PackedVector2Array gpu_points;
    for (const auto &pt : points) {
        Vector2 screen_pos = (pt.position - pan_offset) * zoom_factor;
        gpu_points.push_back(screen_pos);
    }
    draw_polyline(gpu_points, Color(0.0f, 0.8f, 0.8f), 2.0f, true);
}
