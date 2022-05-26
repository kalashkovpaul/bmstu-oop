#include "Transformation.hpp"

Transformation::Transformation(ITransfromation& interface):
    matrix(interface) {}

void Transformation::transform(std::shared_ptr<SceneObject> object) {
    if (object->isVisible()) {
        std::shared_ptr<BaseModel> pModel = std::dynamic_pointer_cast<BaseModel>(object);
        pModel->transform(matrix);
    }
}