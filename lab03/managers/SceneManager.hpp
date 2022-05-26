#ifndef SCENE_MANAGER_HPP_

#define SCENE_MANAGER_HPP_

#include <memory>
#include <string>
#include "Scene/Scene.hpp"
#include "objects/SceneObject.hpp"
#include "creators/creators.hpp"

class SceneManager {
public:
    static void addModel(Scene& scene, const std::shared_ptr<SceneObject> model);

    static void addCamera(Scene& scene, Solution& solution);

private:
    SceneManager() = default;    
};

#endif