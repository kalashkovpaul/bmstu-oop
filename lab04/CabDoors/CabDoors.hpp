#ifndef CAB_DOORS_HPP_

#define CAB_DOORS_HPP_

#include <QObject>
#include <QTimer>
#include "Logger/Logger.hpp"

class CabDoors: public QObject {
    Q_OBJECT

    enum class State {
        opened,
        closed,
        opening,
        closing
    };

public:
    explicit CabDoors(Logger *logger = nullptr);

    void setLogger(Logger *logger);

signals: // out
    void opened();
    void closed();

public slots:
    void startOpening();
    void startClosing();

private slots:
    void open();
    void close();

private:
    State state;
    QTimer openTimer;
    QTimer holdTimer;
    QTimer closeTimer;
    Logger *logger;

private:
    constexpr static int timeToSwitch = 500;
    constexpr static int timeToHold = 500;
};

#endif