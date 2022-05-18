#ifnef MODEL_HPP_

#define MODEL_HPP_

#include <vector>
#include <string>

#include "VisibleObject.hpp"
#include "containers/Vector/Vector.h"
#include "math3D/Point3D/Point3D.h"
#include "math3D/Edge/Edge.h"

class Model: public VisibleObject {
public:
    explicit Model() = default;
    explicit Model(std::string, std::vector<Point3D<double>>, std::vector<Edge>);
    Model(const Model&);
    Model(Model&&) noexcept;

    Model& operator=(const Model&);
    Model& operator=(Model&&) noexcept;

    // friend class Transformation; TODO
    // friend class DrawManager; TODO

private:
    std::string name;
    std::vector<Point3D<double>> vertices;
    std::vector<Edge> edges;
};

#endif