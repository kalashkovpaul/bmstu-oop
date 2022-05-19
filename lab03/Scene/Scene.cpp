#include "Scene.hpp"

void Scene::transform(BaseTransformation& transformation) {
    object.transform(transformation);
}

void Scene::addModel(SceneObject* object) {
    this->object.addModel(object);
}

void Scene::deleteModel(std::size_t index) {
    object.deleteModel(index);
}

void Scene::addCamera(SceneObject* object) {
    this->object.addCamera(object);
}

void Scene::deleteCamera(std::size_t index) {
    object.deleteCamera(index);
}

SceneObject*& Scene::getModel(std::size_t index) {
    return object.getModel(index);
}

SceneObject*& Scene::getCamera(std::size_t index) {
    return object.getCamera(index);
}