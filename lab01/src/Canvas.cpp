#include "Canvas.hpp"
#include "read.hpp"

#include <iostream>

Canvas::Canvas(QWidget *parent) {
    this->parent = parent;
}


void Canvas::paintGL() {
    std::cout << "Painting" << std::endl;
    readRender();
}
