#include "DrawManager.hpp"

void DrawManager::Draw(Scene& scene, BaseDrawer& drawer, Camera* camera) {
    DrawVisitor visitor = DrawVisitor();
    
    for (auto& sceneObject : scene.object.sceneObjects) {
        if (sceneObject->isVisible()) {
            Model* model = reinterpret_cast<Model*>(sceneObject);
            model->acceptDrawVisitor(&visitor, drawer, camera);
        }
    }
}