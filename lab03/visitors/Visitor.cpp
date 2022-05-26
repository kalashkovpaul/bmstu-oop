#include "Visitor.hpp"

Visitor::Visitor(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera):
    drawer(drawer),
    camera(camera) {}

void Visitor::visit(std::shared_ptr<CarcassModelImplementator> implementator) {
    Matrix4x4<double> matrix = camera->getViewMatrix();
    std::vector<Point3D<double>> vertices = implementator->getVertices();
    std::vector<Edge> edges = implementator->getEdges();
    for (const auto& edge : edges) {
        const Point3D<double> p1 = matrix * vertices.at(edge.p1());
        const Point3D<double> p2 = matrix * vertices.at(edge.p2());
        drawer(p1, p2);
    }
}