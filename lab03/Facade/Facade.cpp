#include "Facade.hpp"


Facade::Facade() {
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    scene.addCamera((cr->createSceneObject()));
}

void Facade::executeCommand(Command& command) {
    std::size_t type = command.getType();
    if (type == SceneCommandID)
        command.execute(scene);
    else if (type == ModelViewCommandID)
        command.execute(modelView);
    else if (type == SceneAndViewCommandID)
        command.execute(scene, modelView);
    else if (type == SceneAndSolutionCommandID)
        command.execute(scene, solution);
    else if (type == ViewAndSolutionCommandID)
        command.execute(modelView, solution);
}
