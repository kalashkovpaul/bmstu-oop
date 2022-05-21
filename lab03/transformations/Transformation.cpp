#include "Transformation.hpp"

Transformation::Transformation(ITransfromation& interface):
    matrix(interface) {}

void Transformation::transform(std::shared_ptr<SceneObject> object) {
    if (object->isVisible()) {
        std::shared_ptr<Model> pModel = std::dynamic_pointer_cast<Model>(object);
        for (auto& vertex : pModel->vertices) {
            vertex = matrix * vertex;
        }
    }
}