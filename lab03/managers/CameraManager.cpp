#include "CameraManager.hpp"

void CameraManager::transform(Scene& scene, ICommand& command, std::size_t index) {
    std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(scene.getCamera(index));
    command.execute(camera);
}