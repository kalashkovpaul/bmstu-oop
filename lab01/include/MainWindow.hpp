#pragma once

#include "Canvas.hpp"
#include <QMainWindow>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:

    Canvas *canvas;
};