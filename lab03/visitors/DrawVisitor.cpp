#include "DrawVisitor.hpp"

void DrawVisitor::visit(Model* model, BaseDrawer& drawer, Camera* camera) {
    Matrix4x4<double> matrix = camera->getViewMatrix();
    for (const auto& edge : model->edges) {
        auto p1 = matrix * model->vertices.at(edge.p1());
        auto p2 = matrix * model->vertices.at(edge.p2());
        drawer(p1, p2);
    }
}