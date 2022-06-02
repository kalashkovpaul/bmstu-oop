#ifndef MAINWINDOW_HPP_

#define MAINWINDOW_HPP_

#include <QMainWindow>
#include <QCheckBox>
#include <QVector>
#include "Elevator/Elevator.hpp"

namespace UI {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void called(int floor);
private slots:
    void floorButtonClicked(int i);
    void cabButtonClicked(int i);

private slots:
    void stop(int floor);
    void updateFloor(int floor);

private:
    constexpr static int floorsAmount = 16;
    UI::MainWindow *ui;
    QVector<QCheckBox *> floorButtons;
    QVector<QCheckBox *> cabButtons;
    Elevator elevator;

private:
    void createFloorButtons();
    void createCabButtons();
    void createButtons(QVector<QCheckBox *>& buttons, QLayout *layout, void(MainWindow::*slot)(int));
};

#endif