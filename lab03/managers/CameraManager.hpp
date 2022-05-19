#ifndef CAMERA_MANAGER_HPP_

#define CAMERA_MANAGER_HPP_

#include "Scene/Scene.hpp"
#include "transformations/cameraCommands.hpp"

class CameraManager {
public:
    static void transform(Scene& scene, ICommand& command, std::size_t index);

private:
    CameraManager() = default;
};

#endif