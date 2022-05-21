#ifndef BASE_TRANSFORMATION_HPP_

#define BASE_TRANSFORMATION_HPP_

#include <memory>
#include "objects/SceneObject.hpp"
class SceneObject;

class BaseTransformation {
public:
    BaseTransformation() = default;
    BaseTransformation(const BaseTransformation&) = delete;
    virtual ~BaseTransformation() = default;

    virtual void transform(std::shared_ptr<SceneObject>) = 0;
};

#endif