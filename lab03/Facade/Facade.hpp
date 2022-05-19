#ifndef FACADE_H_
#define FACADE_H_

// #include "controller/controller.hpp" TODO
#include "commands/commands.hpp"
// #include "exceptions/base_exception.hpp" TODO

class Facade {
 public:
  Facade() = default;
  Facade(Facade&) = delete;
  Facade(const Facade&) = delete;
  ~Facade() = default;

  void executeCommand(Command& command);
};

#endif
