#include "CameraManager.hpp"

void CameraManager::transform(Scene& scene, ICommand& command, std::size_t index) {
    Camera* camera = reinterpret_cast<Camera*>(scene.getCamera(index));
    command.execute(camera);
}