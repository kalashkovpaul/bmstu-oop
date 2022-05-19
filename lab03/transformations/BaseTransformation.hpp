#ifndef BASE_TRANSFORMATION_HPP_

#define BASE_TRANSFORMATION_HPP_

#include "Scene.hpp"

class BaseTransformation {
public:
    BaseTransformation() = default;
    BaseTransformation(const BaseTransformation&) = delete;
    virtual ~BaseTransformation() = default;

    virtual void transform(Scene*&) = 0;
};

#endif