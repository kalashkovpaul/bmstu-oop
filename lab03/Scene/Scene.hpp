#ifndef SCENE_HPP_

#define SCENE_HPP_

#include "objects/CompositeObject.hpp"
#include "managers/DrawManager.hpp"

class Scene {
public:
    Scene() = default;
    Scene(const Scene&) = default;
    ~Scene() = default;

    void transform(BaseTransformation& transformation);

    void addModel(std::shared_ptr<SceneObject> object);
    void deleteModel(std::size_t index);

    void addCamera(std::shared_ptr<SceneObject> object);
    void deleteCamera(std::size_t index);

    std::shared_ptr<SceneObject> getModel(std::size_t index);
    std::shared_ptr<SceneObject> getCamera(std::size_t index);

    friend class DrawManager;
private:
    CompositeObject object;
};

#endif