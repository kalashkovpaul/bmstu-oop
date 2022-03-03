#ifndef TRANSFORMMETA_HPP
#define TRANSFORMMETA_HPP

#include "vector3d.hpp"

typedef enum {
    TRANSLATION,
    ROTATION,
    UNIFORM_SCALING
} transformType_t;

typedef struct {
    vector3d_t displacement;
} translation_t;

typedef struct {
    vector3d_t axis;
    double angle;
} rotation_t;

typedef struct uniformScaling {
    double factor;
} uniformScaling_t;

typedef struct {
    transformType_t type;
    union {
        translation_t translation;
        rotation_t rotation;
        uniformScaling_t uniformScaling;
    };
} transformMeta_t;

#endif // TRANSFORMMETA_HPP
