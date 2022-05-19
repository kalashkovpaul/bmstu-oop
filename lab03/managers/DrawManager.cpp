#include "DrawManager.hpp"

void DrawManager::draw(Scene& scene, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {
    std::shared_ptr<Visitor> visitor = std::make_shared<DrawVisitor>();
    
    for (auto sceneObject : scene.object.sceneObjects) {
        if (sceneObject->isVisible()) {
            const std::shared_ptr<Model> model = std::dynamic_pointer_cast<Model>(sceneObject);
            model->acceptDrawVisitor(visitor, drawer, camera);
        }
    }
}