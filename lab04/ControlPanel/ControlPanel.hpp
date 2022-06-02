#ifndef CONTROL_PANEL_HPP_

#define CONTROL_PANEL_HPP_

#include <QObject>
#include <QVector>
#include "Direction/Direction.hpp"
#include "Logger/Logger.hpp"

class ControlPanel: public QObject {
    Q_OBJECT

    enum class State {
        busy,
        idle,
        waiting
    };

public:
    explicit ControlPanel(int floorsAmount, Logger *logger = nullptr);

    void setLogger(Logger *logger);

signals: // in
    void move();
    void stop();
    void called(Direction direction);

signals: // out
    void passedFloor(int floor);
    void stopped(int floor);

public slots:
    void call(int floor);
    void passFloor();
    void lookAround();

private:
    State state;
    const int floorsAmount;
    int floor;
    QVector<bool> isTarget;
    Direction direction;
    Logger *logger;

private:
    int nextTarget() const;
};

#endif