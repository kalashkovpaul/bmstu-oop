#include "vector3d.hpp"

#include <locale.h>

const vector3d_t origin = { 0.0, 0.0, 0.0 };
const vector3d_t unit_x = { 1.0, 0.0, 0.0 };
const vector3d_t unit_y = { 0.0, 1.0, 0.0 };
const vector3d_t unit_z = { 0.0, 0.0, 1.0 };

bool readVector3d(vector3d_t& vector, FILE* file)
{
    setlocale(LC_NUMERIC, "C");
    bool ok = true;
    int tmp = fscanf(file, "%lf %lf %lf", &vector.x, &vector.y, &vector.z);
    if (tmp != 3)
        ok = false;
    return ok;
}

bool readVectors3d(vector3d_t* vertices, const int verticesAmount, FILE* file)
{
    bool ok = true;
    for (int i = 0; i < verticesAmount && ok; i++) {
        vector3d_t& vector = vertices[i];
        ok = readVector3d(vector, file);
        if (!ok)
            printf("readVectors3d error: i = %d\n", i);
    }
    return ok;
}

void writeSingleVector3d(const vector3d_t& vector3d, FILE* file)
{
    setlocale(LC_NUMERIC, "C");
    fprintf(file, "%.6lf %.6lf %.6lf\n", vector3d.x, vector3d.y, vector3d.z);
}

void writeVectors3d(const vector3d_t* vertices, const int verticesAmount, FILE* file)
{
    for (int i = 0; i < verticesAmount; i++)
        writeSingleVector3d(vertices[i], file);
}
