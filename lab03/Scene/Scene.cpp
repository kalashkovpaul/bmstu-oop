#include "Scene.hpp"

void Scene::transform(BaseTransformation& transformation) {
    object.transform(transformation);
}

void Scene::addModel(std::shared_ptr<SceneObject> object) {
    this->object.addModel(object);
}

void Scene::deleteModel(std::size_t index) {
    object.deleteModel(index);
}

void Scene::addCamera(std::shared_ptr<SceneObject> object) {
    this->object.addCamera(object);
}

void Scene::deleteCamera(std::size_t index) {
    object.deleteCamera(index);
}

std::shared_ptr<SceneObject>& Scene::getModel(std::size_t index) {
    return object.getModel(index);
}

std::shared_ptr<SceneObject>& Scene::getCamera(std::size_t index) {
    return object.getCamera(index);
}