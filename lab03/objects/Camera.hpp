#ifndef CAMERA_HPP_

#define CAMERA_HPP_

#include "objects/InvisibleObject.hpp"
#include "math3D/Point3D/Point3D.h"
#include "math3D/Matrix4x4/Matrix4x4.h"
#include "transformations/dimensionalTransformations.hpp"

class Camera: public InvisibleObject {
public:
    Camera();
    Camera(const Point3D<double>&, const Point3D<double>&, double, double, double);

    void setPosition(const Point3D<double>&);
    void setTarget(const Point3D<double>&);

    Matrix4x4<double> getViewMatrix();

    void rotateUpDownSphere(double);
    void rotateLeftRightSphere(double);

    void rollLook(double);
    void rollUp(double);
    void rollRight(double);

private:
    Vector4D<double> look;
    Vector4D<double> up;
    Vector4D<double> right;

    Vector4D<double> position;
    Vector4D<double> target;
};

#endif