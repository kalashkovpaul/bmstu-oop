#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <stdio.h>

struct vector3d_t {
    double x, y, z;
};

extern const vector3d_t origin;
extern const vector3d_t unit_x;
extern const vector3d_t unit_y;
extern const vector3d_t unit_z;

bool readVectors3d(vector3d_t* vertices, const int verticesAmount, FILE* file);

void writeVectors3d(const vector3d_t* vertices, const int verticesAmount, FILE* file);

#endif
