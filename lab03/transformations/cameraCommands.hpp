#ifndef COMMAND_INTERFACE_HPP_

#define COMMAND_INTERFACE_HPP_

#include <memory>
#include "objects/Camera.hpp"
class ICommand {
public:
    ICommand() = default;
    ICommand(const ICommand&) = delete;

    virtual void execute(std::shared_ptr<Camera>&) = 0;
};

namespace cameraCommands {

class RollLook: public ICommand {
public:
    explicit RollLook(double angle);
    RollLook(const RollLook&) = delete;

    void execute(std::shared_ptr<Camera>& camera) override;

private:
    double angle;
};

class RollUp: public ICommand {
public:
    explicit RollUp(double angle);
    RollUp(const RollUp&) = delete;

    void execute(std::shared_ptr<Camera>& camera) override;

private:
    double angle;
};

class RollRight: public ICommand {
public:
    explicit RollRight(double angle);
    RollRight(const RollRight&) = delete;

    void execute(std::shared_ptr<Camera>& camera) override;

private:
    double angle;
};

}

#endif