#include "ITransformation.hpp"

ITransfromation::ITransfromation():
    Matrix4x4<double>() {
    resetMatrix();
}

void ITransfromation::resetMatrix() {
    *(reinterpret_cast<Matrix4x4<double>*>(this)) = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}