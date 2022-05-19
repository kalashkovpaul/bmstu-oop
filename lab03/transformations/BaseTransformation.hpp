#ifndef BASE_TRANSFORMATION_HPP_

#define BASE_TRANSFORMATION_HPP_

#include "objects/SceneObject.hpp"

class BaseTransformation {
public:
    BaseTransformation() = default;
    BaseTransformation(const BaseTransformation&) = delete;
    virtual ~BaseTransformation() = default;

    virtual void transform(SceneObject*&) = 0;
};

#endif