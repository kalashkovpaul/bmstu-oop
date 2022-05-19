#ifndef DIMENSIONAL_TRANSFORMATIONS_HPP_

#define DIMENSIONAL_TRANSFORMATIONS_HPP_

#include <cmath>
#include "ITransformation.hpp"

namespace dimensionalTransformations {

class RotationOX: public ITransfromation {
public:
    explicit RotationOX(double);
    RotationOX(const RotationOX&) = delete;
};

class RotationOY: public ITransfromation {
public:
    explicit RotationOY(double);
    RotationOY(const RotationOY&) = delete;
};

class RotationOZ: public ITransfromation {
public:
    explicit RotationOZ(double);
    RotationOZ(const RotationOZ&) = delete;
};

class Rotation: public ITransfromation {
public:
    explicit Rotation(const Point3D<double>&, double);
    Rotation(const Rotation&) = delete;
};

class Translation: public ITransfromation {
public:
    explicit Translation(const Point3D<double>&);
    Translation(const Translation&) = delete;
};

class Scaling: public ITransfromation {
public:
    explicit Scaling(double);
    Scaling(const Scaling&) = delete;
};

}

#endif