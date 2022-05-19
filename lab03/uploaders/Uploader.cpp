#include "uploaders/Uploader.hpp"
#include "exceptions/uploadExceptions.hpp"

Uploader::Uploader(std::string filename):
    filename(filename) {}

Uploader::~Uploader() {
    this->close();
}

void Uploader::close() {
    if (!isOpen()) {
        file.close();
    }
}

void Uploader::open() {
    if (isOpen()) {
        close();
    }
    file.open(filename);
    if (!file) {
        throw OpenStreamException();
    }
}

bool Uploader::isOpen() const {
    return file.is_open();
}

const Model Uploader::getModel() {
    if (!isOpen()) {
        throw ReadStreamException();
    }
    std::size_t verticesAmount, edgesAmount;
    file >> verticesAmount >> edgesAmount;

    std::vector<Point3D<double>> vertices(verticesAmount);
    for (auto& vertex : vertices) {
        file >> vertex;
    }
    std::vector<Edge> edges(edgesAmount);
    for (auto& edge : edges) {
        file >> edge;
    }
    return Model(filename, vertices, edges);
}
 