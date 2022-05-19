#ifndef MODEL_MANAGER_HPP_

#define MODEL_MANAGER_HPP_

#include "Scene/Scene.hpp"
#include "transformations/BaseTransformation.hpp"

class ModelManager {
public:
    static void transform(Scene& scene, BaseTransformation& transfromation, ssize_t index);

private:
    ModelManager() = default;
};

#endif