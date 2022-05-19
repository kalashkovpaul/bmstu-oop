#include "CompositeObject.hpp"

CompositeObject::CompositeObject(SceneObject* camera) {
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

void CompositeObject::addModel(SceneObject* object) {
    sceneObjects.push_back(reinterpret_cast<Model*>(object));
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
        }
        sceneObjects.erase(sceneObjects.begin() + i);
        modelsAmount--;
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: Model out of range");
    }
}

void CompositeObject::addCamera(SceneObject* object) {
    sceneObjects.push_back(reinterpret_cast<Camera*>(object));
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
        }
        sceneObjects.erase(sceneObjects.begin() + i);
        camerasAmount--;
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: Camera out of range");
    }
}

SceneObject*& CompositeObject::getModel(std::size_t index) {
    if (index < modelsAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (sceneObjects[i]->isVisible()) {
                count++;
                if (count - 1 == index)
                    break;
            }
        }
        return sceneObjects[i];
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: getModel out of range");
    }
}

SceneObject*& CompositeObject::getCamera(std::size_t index) {
    if (index < camerasAmount) {
        std::size_t count = 0;
        std::size_t i = 0;
        while (i < sceneObjects.size()) {
            if (!sceneObjects[i]->isVisible()) {
                count++;
                if (count - 1 == index)
                    break;
            }
        }
        return sceneObjects[i];
    } else {
        throw SceneOutOfRangeException("[ SCENE ]: getCamera     out of range");
    }
}
