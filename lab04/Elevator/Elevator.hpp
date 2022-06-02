#ifndef ELEVATOR_HPP_

#define ELEVATOR_HPP_

#include <QObject>
#include "ControlPanel/ControlPanel.hpp"
#include "Cab/Cab.hpp"

class Elevator: public QObject {
    Q_OBJECT
public:
    explicit Elevator(int floorsAmount, QObject *parent = nullptr, Logger *logger = nullptr);
    
    void setLogger(Logger *logger);

signals: // in
    void called(int floor);

signals: // out
    void stopped(int floor);
    void passedFloor(int floor);

private:
    ControlPanel control;
    Cab cab;
    Logger *logger;
};

#endif