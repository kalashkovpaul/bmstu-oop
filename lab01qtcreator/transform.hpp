#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "transformMeta.hpp"

union transform_t {
    double m[4][4];
    struct {
        double
            m00, m01, m02, m03,
            m10, m11, m12, m13,
            m20, m21, m22, m23,
            m30, m31, m32, m33;
    };
};

transform_t createTransform(const transformMeta_t& transformMeta);

vector3d_t transformVector3d(const transform_t& transform, const vector3d_t& vector3d);

#endif // TRANSFORM_HPP
