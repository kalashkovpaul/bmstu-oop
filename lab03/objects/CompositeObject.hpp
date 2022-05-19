#ifndef COMPOSITE_OBJECT_HPP_

#define COMPOSITE_OBJECT_HPP_

#include "Scene.hpp"
#include "sceneExceptions.hpp"
#include "Model.hpp"
#include "Camera.hpp"

class CompositeObject: public Scene {
    CompositeObject(Scene* camera);

    bool isVisible() const override;

    // void Transform(BaseTransformation& transformation); TODO

    void addModel(Scene* scene);
    void deleteModel(std::size_t index);

    void addCamera(Scene* scene);
    void deleteCamera(std::size_t index);

    Scene*& getModel(std::size_t);
    Scene*& getCamera(std::size_t);

    // friend class DrawManager; TODO

private:
    std::size_t modelsAmount;
    std::size_t camerasAmount;
    std::vector<Scene*> sceneObjects;
};

#endif