#ifndef DRAW_MANAGER_HPP_

#define DRAW_MANAGER_HPP_

#include "Scene/Scene.hpp"
#include "math3D/Matrix4x4/Matrix4x4.h"
#include "gui/drawers.hpp"
#include "visitors/DrawVisitor.hpp"
class Scene;

class DrawManager {
public:
    static void Draw(Scene& scene, BaseDrawer& drawer, Camera* camera);

private:
    DrawManager() = default;
};

#endif