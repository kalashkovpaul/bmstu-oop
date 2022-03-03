#include "vector3d.hpp"

const vector3d_t origin = { 0.0, 0.0, 0.0 };
const vector3d_t unit_x = { 1.0, 0.0, 0.0 };
const vector3d_t unit_y = { 0.0, 1.0, 0.0 };
const vector3d_t unit_z = { 0.0, 0.0, 1.0 };

bool readVector3d(vector3d_t& vector, std::ifstream& file) {
    double x = 0, y = 0, z = 0;
    bool ok = true;
    if (file >> x >> y >> z) {
        vector.x = x;
        vector.y = y;
        vector.z = z;
    } else
        ok = false;
    return ok;
}

bool readVectors3d(std::vector<vector3d_t>& vertices, std::ifstream& file) {
    bool ok = true;
    for (size_t i = 0; i < vertices.size() && ok; i++) {
        vector3d_t& vector = vertices.at(i);
        ok = readVector3d(vector, file);
    }
    return ok;
}
