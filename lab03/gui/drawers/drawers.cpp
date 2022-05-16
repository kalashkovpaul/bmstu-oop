#include "drawers.hpp"

Drawer::Drawer(QGraphicsScene*& graphics_scene)
    : BaseDrawer(), graphicsScene(graphics_scene) {}

Drawer::Drawer(const Drawer& other)
    : BaseDrawer(), graphicsScene(other.graphicsScene) {}

Drawer::~Drawer() {
  graphicsScene = nullptr;
}

void Drawer::operator()(const Point3D<double>& p1, const Point3D<double>& p2) {
  graphicsScene->addLine(p1.x(), p1.y(), p2.x(), p2.y());
}
