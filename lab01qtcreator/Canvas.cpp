#include "Canvas.hpp"

#include <iostream>

Canvas::Canvas(QWidget *parent)
    : QOpenGLWidget(parent),
      clearColor(Qt::red)
{
    setAutoFillBackground(false);
}


void Canvas::paintEvent(QPaintEvent *e) {
    std::cout << "Painting" << std::endl;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(e->rect(), QBrush(QColor(255, 255, 255)));
    readRender();
    painter.end();
}

void Canvas::mouseMoveEvent(QMouseEvent *e) {
    int dx = e->x() - e->globalX();
    int dy = e->y() - e->globalY();
    Qt::MouseButtons buttons = e->buttons();

    if ((dx || dy) && (buttons)) {
        if (buttons == Qt::LeftButton) {
            transformMeta.type = ROTATION;
            const vector3d_t axis = { -0.1 * dy, 0.1 * dx, 0.0 };
            const double angle = 0.01;
            const rotation_t rotation = { axis, angle };
            transformMeta.rotation = rotation;
        } else if (buttons == Qt::RightButton) {
            transformMeta.type = TRANSLATION;
            const vector3d_t displacement = { 0.01 * dx, 0.01 * dy, 0.0 };
            const translation_t translation = { displacement };
            transformMeta.translation = translation;
        }
        readTransform();
        update();
    }

    std::cout << buttons << std::endl;
    std::cout << "Mooove" << std::endl;
}


