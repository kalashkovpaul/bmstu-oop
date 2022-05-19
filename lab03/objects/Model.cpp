#include "Model.hpp"
#include "visitors/DrawVisitor.hpp"

Model::Model(std::string name, std::vector<Point3D<double>> vertices, std::vector<Edge> edges):
    name(name),
    vertices(vertices),
    edges(edges) {}

Model::Model(const Model& other):
    VisibleObject(),
    name(other.name),
    vertices(other.vertices),
    edges(other.edges) {}

Model::Model(Model&& other) noexcept:
    name(std::move(other.name)),
    vertices(std::move(other.vertices)),
    edges(std::move(other.edges)) {}

Model& Model::operator=(const Model& other) {
    if (this != &other) {
        name = other.name;
        vertices = other.vertices;
        edges = other.edges;
    }
    return *this;
}

Model& Model::operator=(Model&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        vertices = std::move(other.vertices);
        edges = std::move(other.edges);
        other.~Model();
    }
    return *this;
}

void Model::acceptDrawVisitor(std::shared_ptr<Visitor>& visitor, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {
    visitor->visit(*this, drawer, camera);
}