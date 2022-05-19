#include "ModelView/ModelView.hpp"

void ModelView::addView(const Model& model) {
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

const Model& ModelView::operator[](std::size_t index) const {
    checkOutOfRange(index);
    return models[index];
}