#include "Facade.hpp"

void Facade::executeCommand(Command& command) {
  command.execute();
}
