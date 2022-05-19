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

void Uploader::getModel(const std::shared_ptr<Model>& model) {
    if (!isOpen()) {
        throw ReadStreamException();
    }
    std::size_t verticesAmount, edgesAmount;
    file >> verticesAmount >> edgesAmount;

    model->vertices.resize(verticesAmount);
    for (auto& vertex : model->vertices) {
        file >> vertex;
    }
    model->edges.resize(edgesAmount);
    std::vector<Edge> edges(edgesAmount);
    for (auto& edge : model->edges) {
        file >> edge;
    }
}
 