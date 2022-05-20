#include "Facade.hpp"


Facade::Facade() {
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    scene.addCamera((cr->createSceneObject()));
}

void Facade::executeCommand(Command& command) {
    command.execute((*this));
}
