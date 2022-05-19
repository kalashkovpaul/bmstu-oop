#include "DrawVisitor.hpp"

void DrawVisitor::visit(Model& model, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {
    Matrix4x4<double> matrix = camera->getViewMatrix();
    for (const auto& edge : model.edges) {
        const Point3D<double> p1 = matrix * model.vertices.at(edge.p1());
        const Point3D<double> p2 = matrix * model.vertices.at(edge.p2());
        drawer(p1, p2);
    }
}