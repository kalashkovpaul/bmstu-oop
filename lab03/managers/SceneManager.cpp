#include "SceneManager.hpp"

void SceneManager::addModel(Scene& scene, const std::shared_ptr<SceneObject> model) {
    scene.addModel(model->clone());
}

void SceneManager::addCamera(Scene& scene, Solution& solution) {
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    scene.addCamera((cr->createSceneObject()));
}