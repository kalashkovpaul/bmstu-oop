#ifndef FACADE_H_
#define FACADE_H_

#include "commands/commands.hpp"
class Command;
#include "Scene/Scene.hpp"
#include "ModelView/ModelView.hpp"
#include "creators/creators.hpp"

class Facade {
public:
    Facade();
    Facade(const Facade&) = delete;
    Facade(Facade&&) = delete;
    ~Facade() = default;

    void executeCommand(Command& command);

    friend Command;
private:
    Scene scene;
    ModelView modelView;
    Solution solution;
};

#endif
