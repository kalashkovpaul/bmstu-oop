#include "uploaders/CarcassUploader.hpp"
#include "exceptions/uploadExceptions.hpp"

CarcassUploader::CarcassUploader(std::string filename):
    filename(filename) {}

CarcassUploader::~CarcassUploader() {
    this->close();
}

void CarcassUploader::close() {
    if (!isOpen()) {
        file.close();
    }
}

void CarcassUploader::open() {
    if (isOpen()) {
        close();
    }
    file.open(filename);
    if (!file) {
        throw OpenStreamException();
    }
}

bool CarcassUploader::isOpen() const {
    return file.is_open();
}

void CarcassUploader::getModel(const std::shared_ptr<BaseModel>& model) {
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
    std::shared_ptr<BaseModelImplementator> imp = std::make_shared<CarcassModelImplementator>(vertices, edges);
    model->setImplementator(imp);
}
 