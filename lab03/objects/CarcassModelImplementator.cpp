#include "objects/CarcassModelImplementator.hpp"

CarcassModelImplementator::CarcassModelImplementator(
    std::vector<Point3D<double>> vertices, std::vector<Edge> edges):
    vertices(vertices),
    edges(edges)  { }

std::vector<Point3D<double>> CarcassModelImplementator::getVertices() const {
    return vertices;
}

std::vector<Edge> CarcassModelImplementator::getEdges() const {
    return edges;
}

void CarcassModelImplementator::draw(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {
    Matrix4x4<double> matrix = camera->getViewMatrix();
    for (const auto& edge : edges) {
        const Point3D<double> p1 = matrix * vertices.at(edge.p1());
        const Point3D<double> p2 = matrix * vertices.at(edge.p2());
        drawer(p1, p2);
    }
}

void CarcassModelImplementator::transform(Matrix4x4<double>& matrix) {
    for (auto& vertex : vertices) {
        vertex = matrix * vertex;
    }
}