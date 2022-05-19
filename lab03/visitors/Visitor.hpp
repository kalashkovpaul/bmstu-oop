#ifndef VISITOR_HPP_

#define VISITOR_HPP_

#include "gui/drawers.hpp"
#include "objects/Model.hpp"
#include "objects/Camera.hpp"

class Visitor {
public:
    explicit Visitor() = default;
    Visitor(const Visitor&) = delete;
    ~Visitor() = default;

    virtual void visit(Model *model, BaseDrawer& drawer, Camera* camera) = 0;
};
#endif