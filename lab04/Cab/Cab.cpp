#include "Cab/Cab.hpp"

Cab::Cab(Object *parent, Logger *logger):
    QObject(parent),
    state(State::stanging),
    doors(parent, logger),
    direction(Direction::stay),
    logger(logger) {
    passFloorTimer.setInterval(timePerFloor);
    passFloorTimer.setSingleShot(true);

    connect(this, &Cab::called, &doors, &CabDoors::startClosing);
    connect(&doors, &CabDoors::closed, this, &Cab::move);
    connect(&passFloorTimer, &QTimer::timeout, this, &Cab::passedFloor);
    connect(this, &Cab::stopped, &doors, &CabDoors::startOpening);
}

void Cab::setLogger(Logger *logger) {
    this->logger = logger;
    doors.setLogger(logger);
}

void Cab::_move() {
    log(logger, "Лифт " + QString(direction == Direction::up ? "поднимается" : "опускается"));
    passFloorTimer.start();
}

void Cab::move() {
    if (state == State::calling || state == State::moving) {
        state = State::moving;
        _move();
    } else if (state == State::standing) {
        emit ready();
    }
}

void Cab::stop() {
    passFloorTimer.stop();
    if (state != State::standing) {
        state = State::standing;
        emit stopped();
    }
}

void Cab::call(Direction direction) {
    if (state == State::standing) {
        this->direction = direction;
        state = State::calling;
        emit called();
    }
}