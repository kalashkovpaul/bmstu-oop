#ifndef SCENE_OBJECT_HPP_

#define SCENE_OBJECT_HPP_

#include <vector>
#include <memory>
#include "transformations/BaseTransformation.hpp"
class BaseTransformation;

class SceneObject {
public:
    SceneObject() = default;
    SceneObject(const SceneObject&) = default;
    virtual ~SceneObject() = default;

    virtual bool isVisible() const { return false; }

    virtual bool transform(BaseTransformation& transformation) { return false; }

    virtual bool addModel(std::shared_ptr<SceneObject> scene) { return false; }
    virtual bool deleteModel(std::size_t index) { return false; }

    virtual bool addCamera(std::shared_ptr<SceneObject> scene) { return false; }
    virtual bool deleteCamera(std::size_t index) { return false; }

    virtual std::shared_ptr<SceneObject> getModel(std::size_t) const { return std::shared_ptr<SceneObject>(nullptr); }
    virtual std::shared_ptr<SceneObject> getCamera(std::size_t) const { return std::shared_ptr<SceneObject>(nullptr); } 

    virtual std::shared_ptr<SceneObject> clone() const = 0;
};

#endif