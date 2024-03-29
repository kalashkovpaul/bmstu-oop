#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QPaintEvent>
#include <QPainter>

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    Canvas(QWidget* parent);
    QPainter painter;

protected:
    virtual void paintEvent(QPaintEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
    virtual void wheelEvent(QWheelEvent* e) override;
    virtual void keyPressEvent(QKeyEvent* e) override;
    virtual void closeEvent(QCloseEvent* e) override;

private:
    int realWidth, realHeight;
    QWidget* parent;
    QColor clearColor;
    int previousX, previousY;
};

#endif
