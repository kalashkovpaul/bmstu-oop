#include "screen.hpp"

vector2d_t project3dOn2d(const vector3d_t& vector3d, const screen_t *screen) {
        vector2d_t vector2d = {
                screen->width / 2 + vector3d.x * screen->cam_dist / (vector3d.z + screen->cam_dist),
                screen->height / 2 - vector3d.y * screen->cam_dist / (vector3d.z + screen->cam_dist)
        };
        vector2d.x *= screen->scale;
        vector2d.y *= screen->scale;
        return vector2d;
}
