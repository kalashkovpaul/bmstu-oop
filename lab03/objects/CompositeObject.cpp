#include "CompositeObject.hpp"
#include <iostream>

CompositeObject::CompositeObject(std::shared_ptr<SceneObject> camera) {
    addCamera(camera);
}

bool CompositeObject::isVisible() const {
    return true;
}

void CompositeObject::transform(BaseTransformation& transformation) {
    for (auto& sceneObject: sceneObjects) {
        transformation.transform(sceneObject);
    }
}

void CompositeObject::addModel(std::shared_ptr<SceneObject> object) {
    // std::shared_ptr<Model> ptr = reinterpret_cast<std::shared_ptr<Model>>(object)
    sceneObjects.push_back(object);
    modelsAmount++;
}

void CompositeObject::deleteModel(std::size_t index) {
    if (index < modelsAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (sceneObjects[i]->isVisible()) {
                count++;
                if (count - 1 == index)
                    break;
            }
            i++;
        }
        sceneObjects.erase(sceneObjects.begin() + i);
        modelsAmount--;
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: Model out of range");
    }
}

void CompositeObject::addCamera(std::shared_ptr<SceneObject> object) {
    // reinterpret_cast<std::shared_ptr<Camera>>(object);
    sceneObjects.push_back(object);
    camerasAmount++;
}

void CompositeObject::deleteCamera(std::size_t index) {
    if (index < camerasAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (!sceneObjects[i]->isVisible()) {
                count++;
                if (count - 1 == index)
                    break;
            }
            i++;
        }
        sceneObjects.erase(sceneObjects.begin() + i);
        camerasAmount--;
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: Camera out of range");
    }
}

std::shared_ptr<SceneObject>& CompositeObject::getModel(std::size_t index) {
    if (index < modelsAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (sceneObjects[i]->isVisible()) {
                count++;
                if (count - 1 == index)
                    break;
            }
            i++;
        }
        return sceneObjects[i];
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: getModel out of range");
    }
}

std::shared_ptr<SceneObject>& CompositeObject::getCamera(std::size_t index) {
    if (index < camerasAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (!(sceneObjects[i]->isVisible())) {
                count++;
                if (count - 1 == index)
                    break;
            }
            i++;
        }
        return sceneObjects[i];
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: getCamera     out of range");
    }
}
