#ifndef SCENE_OBJECT_HPP_

#define SCENE_OBJECT_HPP_

#include <vector>

class SceneObject {
public:
    explicit SceneObject() = default;
    SceneObject(const SceneObject&) = delete;
    virtual ~SceneObject() = default;

    virtual bool isVisible() const = 0;
    
};

#endif