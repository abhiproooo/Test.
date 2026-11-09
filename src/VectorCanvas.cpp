#include "VectorCanvas.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input_event_screen_touch.hpp>
#include <godot_cpp/classes/input_event_screen_drag.hpp>

using namespace godot;

void VectorCanvas::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_tool", "tool"), &VectorCanvas::set_tool);
    ClassDB::bind_method(D_METHOD("add_point", "point"), &VectorCanvas::add_point);
}

void VectorCanvas::set_tool(int p_tool) {
    active_tool = p_tool;
}

void VectorCanvas::add_point(const Vector2 &p_point) {
    points.push_back(VectorPoint(p_point));
    queue_redraw();
}

void VectorCanvas::_unhandled_input(const Ref<InputEvent> &p_event) {
    Ref<InputEventScreenTouch> touch = p_event;
    Ref<InputEventScreenDrag> drag = p_event;

    if (touch.is_valid()) {
        if (touch->is_pressed()) {
            active_touches[touch->get_index()] = touch->get_position();
        } else {
            active_touches.erase(touch->get_index());
        }
    }

    if (drag.is_valid()) {
        active_touches[drag->get_index()] = drag->get_position();
        
        if (active_touches.size() >= 2) {
            return;
        } else if (active_touches.size() == 1) {
            if (active_tool == 1) {
                add_point(drag->get_position());
            }
        }
    }
    
    if (touch.is_valid() && touch->is_pressed() && active_touches.size() == 1) {
        if (active_tool == 1) {
            add_point(touch->get_position());
        }
    }
}

void VectorCanvas::_draw() {
    draw_rect(Rect2(-5000, -5000, 10000, 10000), Color(1, 1, 1));

    Color cross_color(0.8f, 0.8f, 0.8f);
    draw_line(Vector2(-15, 0), Vector2(15, 0), cross_color, 2.0f);
    draw_line(Vector2(0, -15), Vector2(0, 15), cross_color, 2.0f);

    if (points.empty()) return;

    if (points.size() >= 2) {
        PackedVector2Array gpu_points;
        for (const auto &pt : points) {
            gpu_points.push_back(pt.position);
        }
        draw_polyline(gpu_points, Color(0.0f, 0.8f, 0.8f), 2.0f, true);
    }

    for (const auto &pt : points) {
        Color point_color = pt.is_selected ? Color(1.0f, 0.0f, 0.0f) : Color(0.0f, 0.8f, 0.8f);
        float radius = pt.is_selected ? 8.0f : 5.0f;
        draw_circle(pt.position, radius, point_color);
    }
}
