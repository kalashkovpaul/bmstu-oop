#include "CompositeObject.hpp"
#include <iostream>

CompositeObject::CompositeObject(std::shared_ptr<SceneObject> camera) {
    addCamera(camera);
}

bool CompositeObject::isVisible() const {
    return true;
}

bool CompositeObject::transform(BaseTransformation& transformation) {
    for (auto& sceneObject: sceneObjects) {
        transformation.transform(sceneObject);
    }
    return true;
}

bool CompositeObject::addModel(std::shared_ptr<SceneObject> object) {
    sceneObjects.push_back(object);
    modelsAmount++;
    return true;
}

bool CompositeObject::deleteModel(std::size_t index) {
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
    return true;
}

bool CompositeObject::addCamera(std::shared_ptr<SceneObject> object) {
    sceneObjects.push_back(object);
    camerasAmount++;
    return true;
}

bool CompositeObject::deleteCamera(std::size_t index) {
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
    return true;
}

std::shared_ptr<SceneObject> CompositeObject::getModel(std::size_t index) const {
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

std::shared_ptr<SceneObject> CompositeObject::getCamera(std::size_t index) const {
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
        throw SceneOutOfRangeException("[ SCENE ]: getCamera out of range");
    }
}

std::shared_ptr<SceneObject> CompositeObject::clone() const {
    throw SceneCloneException("CompositeObject is not supposed to be cloned");
}