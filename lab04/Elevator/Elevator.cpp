#include "Elevator/Elevator.hpp"

Elevator::Elevator(int floors, Logger *logger):
    control(floors, logger),
    cab(logger),
    logger(logger) {
    connect(this, &Elevator::called, &control, &ControlPanel::call);
    connect(&control, &ControlPanel::called, &cab, &Cab::call);
    connect(&control, &ControlPanel::move, &cab, &Cab::move);
    connect(&control, &ControlPanel::stop, &cab, &Cab::stop);
    connect(&cab, &Cab::passedFloor, &control, &ControlPanel::passFloor);
    connect(&cab, &Cab::ready, &control, &ControlPanel::lookAround);
    connect(&control, &ControlPanel::passedFloor, this, &Elevator::passedFloor);
    connect(&control, &ControlPanel::stopped, this, &Elevator::stopped);
}

void Elevator::setLogger(Logger* logger) {
    this->logger = logger;
    control.setLogger(logger);
    cab.setLogger(logger);
}