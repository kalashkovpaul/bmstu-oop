#include "Facade.hpp"


Facade::Facade() {
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    std::unique_ptr<SceneObject> ptr = cr->createSceneObject();
    scene.addCamera(ptr.get());
    
    // scene.addCamera((cr->createSceneObject()).get());
}

void Facade::executeCommand(Command& command) {
    command.execute((*this));
}
