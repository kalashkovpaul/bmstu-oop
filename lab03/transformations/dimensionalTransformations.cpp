#include "dimensionalTransformations.hpp"

using namespace dimensionalTransformations;

RotationOX::RotationOX(double angle): ITransfromation() {
    resetMatrix();
    const auto c = std::cos(angle);
    const auto s = std::sin(angle);

    (*this)[1][1] = c;
    (*this)[1][2] = s;
    (*this)[2][1] = -s;
    (*this)[2][2] = c;
}

RotationOY::RotationOY(double angle): ITransfromation() {
    resetMatrix();
    const auto c = std::cos(angle);
    const auto s = std::sin(angle);

    (*this)[0][0] = c;
    (*this)[0][2] = s;
    (*this)[2][0] = -s;
    (*this)[2][2] = c;
}

RotationOZ::RotationOZ(double angle): ITransfromation() {
    resetMatrix();
    const auto c = std::cos(angle);
    const auto s = std::sin(angle);

    (*this)[0][0] = c;
    (*this)[0][1] = s;
    (*this)[1][0] = -s;
    (*this)[1][1] = c;
}

Rotation::Rotation(const Point3D<double>& offset, double angle): ITransfromation() {
    resetMatrix();
    const auto c = std::cos(angle);
    const auto s = std::sin(angle);
    const auto _1c = 1 - c;

    (*this)[0][0] = c + _1c * offset.x() * offset.x();
    (*this)[1][0] = _1c * offset.x() * offset.y() - s * offset.z();
    (*this)[2][0] = _1c * offset.x() * offset.z() + s * offset.y();
    (*this)[0][1] = _1c * offset.y() * offset.x() + s * offset.z();
    (*this)[1][1] = c + _1c * offset.y() * offset.y();
    (*this)[2][1] = _1c * offset.y() * offset.z() - s * offset.x();
    (*this)[0][2] = _1c * offset.z() * offset.x() - s * offset.y();
    (*this)[1][2] = _1c * offset.z() * offset.y() + s * offset.x();
    (*this)[2][2] = c + _1c * offset.z() * offset.z();
}

Translation::Translation(const Point3D<double>& offset): ITransfromation() {
    resetMatrix();
    (*this)[0][3] = offset.x();
    (*this)[1][3] = offset.y();
    (*this)[2][3] = offset.z();    
}

Scaling::Scaling(double factor): ITransfromation() {
    resetMatrix();
    (*this)[0][0] = factor;
    (*this)[1][1] = factor;
    (*this)[2][2] = factor;    
}