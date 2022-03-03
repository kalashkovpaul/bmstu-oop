#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Canvas.hpp"
#include "vector3d.hpp"
#include "vector2d.hpp"

struct screen_t {
    double width;
    double height;
    double cam_dist;
    double scale;
    Canvas* canvas;
};

vector2d_t project3dOn2d(const vector3d_t& vector3d, const screen_t& screen);

#endif // SCREEN_HPP
