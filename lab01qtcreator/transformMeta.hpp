#ifndef TRANSFORMMETA_HPP
#define TRANSFORMMETA_HPP

#include "vector3d.hpp"

enum transformType_t {
    TRANSLATION,
    ROTATION,
    UNIFORM_SCALING
};

struct translation_t {
    vector3d_t displacement;
};

struct rotation_t {
    vector3d_t axis;
    double angle;
};

struct uniformScaling_t {
    double factor;
};

struct transformMeta_t {
    transformType_t type;
    union {
        translation_t translation;
        rotation_t rotation;
        uniformScaling_t uniformScaling;
    };
};

#endif // TRANSFORMMETA_HPP
