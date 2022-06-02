#include "CabDoors/CabDoors.hpp"

CabDoors::CabDoors(Logger *logger):
    state(State::opened),
    logger(logger) {
    openTimer.setInterval(timeToSwitch);
    openTimer.setSingleShot(true);

    closeTimer.setInterval(timeToSwitch);
    closeTimer.setSingleShot(true);

    holdTimer.setInterval(timeToHold);
    holdTimer.setSingleShot(true);

    connect(&openTimer, &QTimer::timeout, this, &CabDoors::open);
    connect(&closeTimer, &QTimer::timeout, this, &CabDoors::close);
    connect(&holdTimer, &QTimer::timeout, this, &CabDoors::startClosing);
    connect(this, &CabDoors::opened, &holdTimer, static_cast<void (QTimer::*)()>(&QTimer::start));
}

void CabDoors::setLogger(Logger *logger) {
    this->logger = logger;
}

void CabDoors::startOpening() {
    if (state == State::closed || state == State::closing) {
        log(logger, "Двери открываются");
        int timeToStart = timeToSwitch;
        if (state == State::closing) {
            timeToStart -= closeTimer.remainingTime();
            closeTimer.stop();
        }
        state = State::opening;
        openTimer.start(timeToStart);
    }
}

void CabDoors::startClosing() {
    if (state == State::opened) {
        log(logger, "Двери закрываются");
        state = State::closing;
        closeTimer.start();
    } else if (state == State::closed) {
        emit closed();
    }
}

void CabDoors::open() {
    if (state == State::opening) {
        log(logger, "Двери открыты");
        state = State::opened;
        emit opened();
    }
}

void CabDoors::close() {
    if (state == State::closing) {
        log(logger, "Двери закрыты");
        state = State::closed;
        emit closed();
    }
}