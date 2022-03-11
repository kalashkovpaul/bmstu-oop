#pragma once

#include <QOpenGLWidget>

class Canvas : public QOpenGLWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent);

protected:
    void paintGl();

private:
    int realWidth, realHeight;
    QWidget *parent;


};