#ifndef VISITOR_HPP_

#define VISITOR_HPP_

#include <memory>
#include "objects/CarcassModelImplementator.hpp"
#include "gui/drawers.hpp"
#include "objects/Camera.hpp"

class Visitor {
public:
    Visitor(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera);

    void visit(std::shared_ptr<CarcassModelImplementator> implementator);
private:
    BaseDrawer& drawer;
    const std::shared_ptr<Camera>& camera;
};

#endif