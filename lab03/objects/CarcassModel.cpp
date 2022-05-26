#include "objects/CarcassModel.hpp"

CarcassModel::CarcassModel(const CarcassModel& other) {
    *this = other;
}

CarcassModel::CarcassModel(CarcassModel&& other) {
    *this = other;
}

CarcassModel& CarcassModel::operator=(const CarcassModel& other) {
    if (this != &other) {
        this->implementator = other.implementator;
    }
    return *this;
}

CarcassModel& CarcassModel::operator=(CarcassModel&& other) noexcept {
    if (this != &other) {
        this->implementator = other.implementator;
        other.~CarcassModel();
    }
    return *this;
}

void CarcassModel::draw(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {
    implementator->draw(drawer, camera);
}

void CarcassModel::transform(Matrix4x4<double>& matrix) {
    implementator->transform(matrix);
}

std::shared_ptr<SceneObject> CarcassModel::clone() const {
    return std::make_shared<CarcassModel>(*this);
}