#ifndef DRAW_VISITOR_HPP_

#define DRAW_VISITOR_HPP_

#include "visitors/Visitor.hpp"
#include "math3D/Matrix4x4/Matrix4x4.h"
#include "gui/drawers.hpp"

class DrawVisitor: public Visitor {
public:
    explicit DrawVisitor() = default;
    DrawVisitor(const DrawVisitor&) = delete;
    ~DrawVisitor() = default;
    void visit(Model& model, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) override;
};

#endif