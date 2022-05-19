#include "DrawManager.hpp"

void DrawManager::draw(Scene& scene, BaseDrawer& drawer, Camera* camera) {
    DrawVisitor visitor = DrawVisitor();
    
    for (SceneObject* sceneObject : scene.object.sceneObjects) {
        if (sceneObject->isVisible()) {
            Model* model = reinterpret_cast<Model*>(sceneObject);
            model->acceptDrawVisitor(&visitor, drawer, camera);
        }
    }
}