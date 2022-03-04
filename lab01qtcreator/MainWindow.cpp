#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    canvas = new Canvas(this);
    canvas->resize(900, 900);
}

void MainWindow::initCanvas()
{
    canvas->QWidget::setStyleSheet("background-color: red");
}
