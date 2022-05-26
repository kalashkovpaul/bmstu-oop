#ifndef COMPOSITE_OBJECT_HPP_

#define COMPOSITE_OBJECT_HPP_

#include "objects/SceneObject.hpp"
#include "exceptions/sceneExceptions.hpp"
#include "objects/BaseModel.hpp"
#include "objects/Camera.hpp"
#include "transformations/BaseTransformation.hpp"

class CompositeObject: public SceneObject {
public:
    CompositeObject() = default;
    CompositeObject(std::shared_ptr<SceneObject> camera);

    bool isVisible() const override;

    bool transform(BaseTransformation& transformation) override;

    bool addModel(std::shared_ptr<SceneObject> scene) override;
    bool deleteModel(std::size_t index) override;

    bool addCamera(std::shared_ptr<SceneObject> scene) override;
    bool deleteCamera(std::size_t index) override;

    std::shared_ptr<SceneObject> getModel(std::size_t) const override;
    std::shared_ptr<SceneObject> getCamera(std::size_t) const override;

    std::shared_ptr<SceneObject> clone() const;

    friend class DrawManager;

private:
    std::size_t modelsAmount = 0;
    std::size_t camerasAmount = 0;
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
};

#endif