#ifndef TRANSFORMATION_INTERACE_HPP_

#define TRANSFORMATION_INTERACE_HPP_

#include "math3D/Matrix4x4/Matrix4x4.h"

class ITransfromation: public Matrix4x4<double> {
public:
    ITransfromation();
    ITransfromation(const ITransfromation&) = delete;

protected:
    void resetMatrix();
};

#endif