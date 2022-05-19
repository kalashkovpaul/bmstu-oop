#include "Transformation.hpp"

Transformation::Transformation(ITransfromation& interface):
    matrix(interface) {}

void Transformation::transform(Scene*& object) {
    if (object->isVisible()) {
        Model* pModel = reinterpret_cast<Model*>(object);
        for (auto& vertex : pModel->vertices) {
            vertex = matrix * vertex;
        }
    }
}