#include "Canvas.hpp"
#include "global.hpp"
#include "read.hpp"
#include "transformMeta.hpp"
#include "vector3d.hpp"

#include <iostream>

Canvas::Canvas(QWidget* parent)
    : QOpenGLWidget(parent)
    , clearColor(Qt::red)
{
    setAutoFillBackground(false);
    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);
    previousX = -1;
    previousY = -1;
}

void Canvas::paintEvent(QPaintEvent* e)
{
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(e->rect(), QBrush(QColor(255, 255, 255)));
    readRender();
    painter.end();
}

void Canvas::mouseMoveEvent(QMouseEvent* e)
{
    int dx = e->globalX() - previousX;
    int dy = previousY - e->globalY();
    previousX = e->globalX();
    previousY = e->globalY();

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

}

void Canvas::wheelEvent(QWheelEvent* e)
{
    transformMeta.type = UNIFORM_SCALING;
    if (e->delta() > 0)
        transformMeta.uniformScaling.factor = 1.0 / 0.9;
    else
        transformMeta.uniformScaling.factor = 0.9;
    readTransform();
    update();
}

void Canvas::keyPressEvent(QKeyEvent* e)
{
    if (e->matches(QKeySequence::Save)) {
        readSave();
    } else if (e->matches(QKeySequence::Refresh)) {
        readLoad();
        update();
    }
}
