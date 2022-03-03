#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Canvas.hpp"
#include <QMainWindow>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void initCanvas();
    Canvas *canvas;
};

#endif
