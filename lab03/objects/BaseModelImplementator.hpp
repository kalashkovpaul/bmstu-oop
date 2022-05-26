#ifndef BASE_MODEL_IMPLEMENTATOR_HPP_

#define BASE_MODEL_IMPLEMENTATOR_HPP_

#include "gui/drawers.hpp"
#include "objects/Camera.hpp"

class BaseModelImplementator {
public:
    virtual ~BaseModelImplementator() = default;

    virtual void draw(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) = 0;

    virtual void transform(Matrix4x4<double>& matrix) = 0;
};

#endif