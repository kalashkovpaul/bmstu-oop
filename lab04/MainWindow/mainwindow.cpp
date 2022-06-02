#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <functional>

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    floorButtons(floorsAmount),
    cabButtons(floorsAmount),
    elevator(floorsAmount) {
    ui->setupUi(this);
    ui->logger->setReadOnly(true);
    elevator.setLogger(ui->logger);

    createFloorButtons();
    createCabButtons();

    connect(this, &MainWindow::called, &elevator, &Elevator::called);
    connect(&elevator, &Elevator::stopped, this, &MainWindow::stop);
    connect(&elevator, &Elevator::passedFloor, this, &MainWindow::updateFloor);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createButtons(QVector<QCheckBox*>& buttons, QLayout *layout, \
    void(MainWindow::*slot)(int)) {
    for (int i = floorsAmount - 1; i >= 0; --i) {
        buttons[i] = new QCheckBox(QString::number(i + 1));
        layout->addWidget(buttons[i]);
        connect(buttons[i], &QCheckBox::clicked, std::bind(slot, this, i));
    }
}

void MainWindow::createFloorButtons() {
    createButtons(floorButtons, ui->floorsGroupBox->layout(), &MainWindow::floorButtonClicked);
}

void MainWindow::createCabButtons() {
    createButtons(cabButtons, ui->cabGroupBox->layout(), &MainWindow::cabButtonClicked);
}

void MainWindow::floorButtonClicked(int i) {
    floorButtons[i]->setEnabled(false);
    emit called(i);
}

void MainWindow::cabButtonClicked(int i) {
    cabButtons[i]->setEnabled(false);
    emit called(i);
}

void uncheck(QCheckBox *checkbox) {
    checkbox->setChecked(false);
    checkbox->setEnabled(true);
}

void MainWindow::stop(int floor) {
    uncheck(floorButtons[floor]);
    uncheck(cabButtons[floor]);
}

void MainWindow::updateFloor(int floor) {
    ui->lcdNumber->display(floor + 1);
}