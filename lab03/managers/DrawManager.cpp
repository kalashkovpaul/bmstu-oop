#include "DrawManager.hpp"

void DrawManager::draw(Scene& scene, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) {    
    for (auto sceneObject : scene.object.sceneObjects) {
        if (sceneObject->isVisible()) {
            const std::shared_ptr<BaseModel> model = std::dynamic_pointer_cast<BaseModel>(sceneObject);
            model->draw(drawer, camera);
        }
    }
}