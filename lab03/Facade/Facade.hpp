#ifndef FACADE_H_
#define FACADE_H_

#include <string>
#include <map>
// #include "controller/controller.hpp" TODO
#include "commands/commands.h"
#include "managers/BaseManager.hpp"
// #include "exceptions/base_exception.hpp" TODO

class Facade {
 public:
  Facade();
  Facade(Facade&) = delete;
  Facade(const Facade&) = delete;
  ~Facade() = default;

  void executeCommand(Command& command);
};

#endif
