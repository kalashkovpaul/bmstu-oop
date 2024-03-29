#ifndef ELEVATOR_HPP_

#define ELEVATOR_HPP_

#include <QObject>
#include <memory>
#include "ControlPanel/ControlPanel.hpp"
#include "Cab/Cab.hpp"

class Elevator: public QObject {
    Q_OBJECT
public:
    explicit Elevator(int floorsAmount, Logger *logger = nullptr);
    
    void setLogger(Logger *logger);

signals:
    void called(int floor);

signals:
    void stopped(int floor);
    void passedFloor(int floor);

private:
    ControlPanel control;
    Cab cab;
    Logger *logger;
};

#endif