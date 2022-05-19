#ifndef MODEL_HPP_

#define MODEL_HPP_

#include <vector>
#include <string>

class Visitor;
class Camera;
#include "containers/Vector/Vector.h"
#include "math3D/Point3D/Point3D.h"
#include "math3D/Edge/Edge.h"
#include "gui/drawers.hpp"
#include "objects/VisibleObject.hpp"

class Model: public VisibleObject {
public:
    explicit Model() = default;
    explicit Model(std::string, std::vector<Point3D<double>>, std::vector<Edge>);
    Model(const Model&);
    Model(Model&&) noexcept;

    Model& operator=(const Model&);
    Model& operator=(Model&&) noexcept;

    void acceptDrawVisitor(Visitor* visitor, BaseDrawer& drawer, Camera* camera);

    friend class Transformation;
    friend class DrawManager;
    friend class DrawVisitor;

private:
    std::string name;
    std::vector<Point3D<double>> vertices;
    std::vector<Edge> edges;
};

#endif