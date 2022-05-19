#include "ModelView/ModelView.hpp"

void ModelView::addView(const std::shared_ptr<SceneObject>& model) {
    models.push_back(model);
}

void ModelView::checkOutOfRange(std::size_t index) const {
    if (index > models.size()) {
        throw ModelViewOutOfRangeException();
    }
}

void ModelView::deleteView(std::size_t index) {
    checkOutOfRange(index);
    models.erase(models.begin() +  index);
}

const std::shared_ptr<SceneObject>& ModelView::operator[](std::size_t index) const {
    checkOutOfRange(index);
    return models[index];
}