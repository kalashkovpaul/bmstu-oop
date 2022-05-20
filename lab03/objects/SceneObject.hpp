#ifndef SCENE_OBJECT_HPP_

#define SCENE_OBJECT_HPP_

#include <vector>
#include <memory>

class SceneObject {
public:
    explicit SceneObject() = default;
    SceneObject(const SceneObject&) = default;
    virtual ~SceneObject() = default;

    virtual std::shared_ptr<SceneObject> clone() const = 0;

    virtual bool isVisible() const = 0;
};

#endif