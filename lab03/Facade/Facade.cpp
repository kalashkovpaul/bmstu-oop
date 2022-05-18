#include "Facade.hpp"

void Facade::ExecuteCommand(Command& command) {
  command.execute();
}
