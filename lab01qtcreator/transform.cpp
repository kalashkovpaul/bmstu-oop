#include "transform.hpp"

#include <assert.h>
#include <cmath>

const transform_t identity = { { { 1.0, 0.0, 0.0, 0.0 },
    { 0.0, 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 0.0, 1.0 } } };

transform_t createTranslationTransform(const vector3d_t& displacement)
{
    transform_t transform = identity;
    transform.m30 = displacement.x;
    transform.m31 = displacement.y;
    transform.m32 = displacement.z;
    return transform;
}

transform_t translate(const translation_t& translation)
{
    const vector3d_t displacement = translation.displacement;
    return createTranslationTransform(displacement);
}

transform_t createRotationTransform(const vector3d_t& axis, double angle)
{
    transform_t transform = identity;
    const double sinA = sin(angle);
    const double cosA = cos(angle);
    const double complementCosA = 1.0 - cosA;
    transform.m00 = cosA + axis.x * axis.x * complementCosA;
    transform.m11 = cosA + axis.y * axis.y * complementCosA;
    transform.m22 = cosA + axis.z * axis.z * complementCosA;
    double tmpN = axis.x * axis.y * complementCosA;
    double tmpM = axis.z * sinA;
    transform.m01 = tmpN - tmpM;
    transform.m10 = tmpN + tmpM;
    tmpN = axis.z * axis.x * complementCosA;
    tmpM = axis.y * sinA;
    transform.m02 = tmpN + tmpM;
    transform.m20 = tmpN - tmpM;
    tmpN = axis.y * axis.z * complementCosA;
    tmpM = axis.x * sinA;
    transform.m12 = tmpN - tmpM;
    transform.m21 = tmpN + tmpM;
    return transform;
}

transform_t rotate(const rotation_t& rotate)
{
    const vector3d_t axis = rotate.axis;
    const double angle = rotate.angle;
    return createRotationTransform(axis, angle);
}

transform_t createUniformScalingTransform(const double factor)
{
    transform_t transform = identity;
    transform.m00 = transform.m11 = transform.m22 = factor;
    return transform;
}

transform_t uniformScale(const uniformScaling_t& uniformScaling)
{
    const double factor = uniformScaling.factor;
    return createUniformScalingTransform(factor);
}

transform_t createTransform(const transformMeta_t& transformMeta)
{
    transform_t transform = identity;
    switch (transformMeta.type) {
    case TRANSLATION:
        transform = translate(transformMeta.translation);
        break;
    case ROTATION:
        transform = rotate(transformMeta.rotation);
        break;
    case UNIFORM_SCALING:
        transform = uniformScale(transformMeta.uniformScaling);
        break;
    default:
        assert(0);
    }
    return transform;
}

vector3d_t transformVector3d(const transform_t& transform, const vector3d_t& vector3d)
{
    double a[4] = { vector3d.x, vector3d.y, vector3d.z, 1.0 };
    double b[4] = { 0.0, 0.0, 0.0, 0.0 };
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            b[i] += a[j] * transform.m[j][i];
    vector3d_t result = { b[0] / b[3], b[1] / b[3], b[2] / b[3] };
    return result;
}
