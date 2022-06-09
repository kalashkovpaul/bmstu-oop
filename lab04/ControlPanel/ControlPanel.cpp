#include "ControlPanel/ControlPanel.hpp"
#include <iostream>

ControlPanel::ControlPanel(int floors, Logger *logger):
    state(State::idle),
    floorsAmount(floorsAmount),
    floor(0),
    isTarget(floorsAmount, false),
    direction(Direction::stay),
    logger(logger) {}

void ControlPanel::setLogger(Logger *logger) {
    this->logger = logger;
}

void ControlPanel::call(int floor) {
    log(logger, "Лифт вызван на " + QString::number(floor + 1) + " этаж");
    isTarget[floor] = true;
    if (state == State::idle) {
        state = State::busy;
        if (this->floor == floor) {
            emit stop();
            emit stopped(floor);
        } else {
            const int target = floor;
            Q_ASSERT(0 <= target && target < floorsAmount);
            direction = dir(target, this->floor);
            emit called(direction);
        }
    }
}

void ControlPanel::passFloor() {
    floor += direction;
    emit passedFloor(floor);
    log(logger, "Лифт " + \
        QString(direction == Direction::up ? "поднялся" : "опустился") + " с " + \
        QString::number(floor - direction + 1) + " на " + QString::number(floor + 1) + " этаж");
    state = State::busy;
    if (isTarget[floor]) {
        log(logger, "Лифт остановился на " + QString::number(floor + 1) + " этаже");
        isTarget[floor] = false;
        emit stop();
        emit stopped(floor);
    } else {
        emit move();
    }
}

int ControlPanel::nextTarget() const {
    for (int target = floor + direction; 0 <= target && target < floorsAmount; target += direction) 
        if (isTarget[target])
            return target;
    for (int target = floor - direction; 0 <= target && target < floorsAmount; target -= direction) 
        if (isTarget[target])
            return target;
    return -1;
}

void ControlPanel::lookAround() {
    if (state == State::busy) {
        const int target = nextTarget();
        state = State::idle;
        if (0 <= target && target <= floorsAmount) {
            direction = dir(target, floor);
            emit called(direction);
        }
    }
}