#include "cameraCommands.hpp"

namespace cameraCommands {

RollLook::RollLook(double angle):
    angle(angle) {}

void RollLook::execute(std::shared_ptr<Camera>& camera) {
    camera->rollLook(angle);
}

RollUp::RollUp(double angle):
    angle(angle) {}

void RollUp::execute(std::shared_ptr<Camera>& camera) {
    camera->rollUp(angle);
}

RollRight::RollRight(double angle):
    angle(angle) {}

void RollRight::execute(std::shared_ptr<Camera>& camera) {
    camera->rollRight(angle);
}

}