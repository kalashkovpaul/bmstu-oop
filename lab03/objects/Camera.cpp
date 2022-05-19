#include "Camera.hpp"

Camera::Camera() {
    right[0] = right[3] = 1;
    up[0] = up[3] = 1;
    look[2] = look[3] = 1;
}

Camera::Camera(const Point3D<double>& position, const Point3D<double>& target, \
    double look, double up, double right) {
    this->position = position.toVector4D();
    this->target = target.toVector4D();
    rollLook(look);
    rollUp(up);
    rollRight(right);
}

void Camera::setPosition(const Point3D<double>& position) {
    this->position = position.toVector4D();
}

void Camera::setTarget(const Point3D<double>& target) {
    this->target = target.toVector4D();
}

Matrix4x4<double> Camera::getViewMatrix() {
    look.normalize();
    up = Vector4D<double>::cross(look, right);
    up.normalize();
    right = Vector4D<double>::cross(up, look);
    right.normalize();

    const double x = -Vector4D<double>::dot(right, position);
    const double y = -Vector4D<double>::dot(up, position);
    const double z = -Vector4D<double>::dot(look, position);

    Matrix4x4<double> tmp = {
        {right[0],  up[0], look[0], 0}, 
        {right[1],  up[1], look[1], 0}, 
        {right[2],  up[2], look[2], 0}, 
        {x, y, z, 1}
    };
    return tmp;
}

void Camera::rotateUpDownSphere(double angle) {
    Point3D<double> point(up[0], up[1], up[2]);
    const Matrix4x4<double> transform = dimensionalTransformations::Rotation(point, angle);
    right = transform * right;
    look = transform * look;
    point = Point3D<double>(target[0], target[1], target[2]);
    const Matrix4x4<double> translation = dimensionalTransformations::Translation(point);
    position = position * (translation * -1.0) * transform * translation;
}

void Camera::rotateLeftRightSphere(double angle) {
    Point3D<double> point(right[0], right[1], right[2]);
    const Matrix4x4<double> transform = dimensionalTransformations::Rotation(point, angle);
    up = transform * up;
    look = transform * look;
    point = Point3D<double>(target[0], target[1], target[2]);
    const Matrix4x4<double> translation = dimensionalTransformations::Translation(point);
    position = position * (translation * -1.0) * transform * translation;
}

void Camera::rollLook(double angle) {
    Point3D<double> point(look[0], look[1], look[2]);
    const Matrix4x4<double> transform = dimensionalTransformations::Rotation(point, angle);
    right = transform * right;
    up = transform * up;
}

void Camera::rollUp(double angle) {
    Point3D<double> point(up[0], up[1], up[2]);
    const Matrix4x4<double> transform = dimensionalTransformations::Rotation(point, angle);
    right = transform * right;
    look = transform * look;
}

void Camera::rollRight(double angle) {
    Point3D<double> point(right[0], right[1], right[2]);
    const Matrix4x4<double> transform = dimensionalTransformations::Rotation(point, angle);
    look = transform * look;
    up = transform * up;
}
