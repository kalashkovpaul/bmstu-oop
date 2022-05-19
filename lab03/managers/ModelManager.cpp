#include "ModelManager.hpp"

void ModelManager::transform(Scene& scene, BaseTransformation& transformation, std::size_t index) {
    if (index == -1) {
        scene.transform(transformation);
    } else {
        transformation.transform(scene.getModel(index));
    }
}
