#ifndef CARCASS_MODEL_IMPLEMENTATOR_HPP_

#define CARCASS_MODEL_IMPLEMENTATOR_HPP_

#include <string>
#include <vector>
#include "objects/BaseModelImplementator.hpp"
#include "math3D/Point3D/Point3D.h"
#include "math3D/Edge/Edge.h"

class CarcassModelImplementator: public BaseModelImplementator {
public:
    CarcassModelImplementator(std::vector<Point3D<double>>, std::vector<Edge>);

    void draw(BaseDrawer& drawer, const std::shared_ptr<Camera>& camera) override;
    
    void transform(Matrix4x4<double>& matrix) override;

private:
    std::vector<Point3D<double>> vertices;
    std::vector<Edge> edges;
};

#endif