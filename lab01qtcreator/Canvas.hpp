#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPaintEvent>
#include <QPainter>
#include "vector2d.hpp"
#include "global.hpp"
#include "read.hpp"

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    Canvas(QWidget *parent);
    void drawPointFromVector(const vector2d_t& vector2d);
    QPainter painter;

protected:
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;

private:
    int realWidth, realHeight;
    QWidget *parent;
    QColor clearColor;
};

#endif
