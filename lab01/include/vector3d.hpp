#pragma once

#include <iostream>
#include <vector>
#include <fstream>

typedef union {
    typedef struct {
        double x, y, z;
    } vector; 
    double m[3];
} vector3d_t;

extern const vector3d_t origin;
extern const vector3d_t unit_x;
extern const vector3d_t unit_y;
extern const vector3d_t unit_z;


bool readVectors3d(std::vector<vector3d_t>& vertices, const std::ifstream& file);

