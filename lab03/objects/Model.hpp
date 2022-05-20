#ifndef MODEL_HPP_

#define MODEL_HPP_

#include <vector>
#include <string>
#include <iostream>

class Visitor;
class Camera;
#include "containers/Vector/Vector.h"
#include "math3D/Point3D/Point3D.h"
#include "math3D/Edge/Edge.h"
#include "gui/drawers.hpp"
#include "uploaders/Uploader.hpp"
#include "objects/VisibleObject.hpp"

class Model: public VisibleObject {
public:
    explicit Model() = default;
    explicit Model(std::string, std::vector<Point3D<double>>, std::vector<Edge>);
    Model(const Model&);
    Model(Model&&) noexcept;

    Model& operator=(const Model&);
    Model& operator=(Model&&) noexcept;

    void acceptDrawVisitor(std::shared_ptr<Visitor>& visitor, BaseDrawer& drawer, const std::shared_ptr<Camera>& camera);

    std::shared_ptr<SceneObject> clone() const override;

    friend class Transformation;
    friend class DrawManager;
    friend class DrawVisitor;
    friend class Uploader;
    
private:
    std::string name;
    std::vector<Point3D<double>> vertices;
    std::vector<Edge> edges;
};

#endif