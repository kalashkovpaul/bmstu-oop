#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <iostream>
#include <vector>
#include <fstream>

struct vector3d_t {
    double x, y, z;
};

extern const vector3d_t origin;
extern const vector3d_t unit_x;
extern const vector3d_t unit_y;
extern const vector3d_t unit_z;


bool readVectors3d(std::vector<vector3d_t>& vertices, std::ifstream& file);

#endif

