#ifndef CAB_HPP_

#define CAB_HPP_

#include <QObject>
#include "Direction/Direction.hpp"
#include "CabDoors/CabDoors.hpp"

class Cab: public QObject {
    Q_OBJECT

    enum class State {
        standing,
        calling,
        moving
    };

public:
    explicit Cab(Logger* logger = nullptr);

    void setLogger(Logger* logger);

signals:
    void called();
    void stopped();

signals:
    void passedFloor();
    void ready();

public slots:
    void move();
    void stop();
    void call(Direction direction);

private:
    State state;
    CabDoors doors;
    Direction direction;
    QTimer passFloorTimer;
    Logger* logger;

private:
    void _move();
private:
    constexpr static int timePerFloor = 1000;
};

#endif