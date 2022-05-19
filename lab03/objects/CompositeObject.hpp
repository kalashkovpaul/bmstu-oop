#ifndef COMPOSITE_OBJECT_HPP_

#define COMPOSITE_OBJECT_HPP_

#include "objects/SceneObject.hpp"
#include "exceptions/sceneExceptions.hpp"
#include "objects/Model.hpp"
#include "objects/Camera.hpp"
#include "transformations/BaseTransformation.hpp"

class CompositeObject: public SceneObject {
public:
    CompositeObject() = default;
    CompositeObject(std::shared_ptr<SceneObject> camera);

    bool isVisible() const override;

    void transform(BaseTransformation& transformation);

    void addModel(std::shared_ptr<SceneObject> scene);
    void deleteModel(std::size_t index);

    void addCamera(std::shared_ptr<SceneObject> scene);
    void deleteCamera(std::size_t index);

    std::shared_ptr<SceneObject>& getModel(std::size_t);
    std::shared_ptr<SceneObject>& getCamera(std::size_t);

    friend class DrawManager;

private:
    std::size_t modelsAmount = 0;
    std::size_t camerasAmount = 0;
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
};

#endif