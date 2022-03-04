#ifndef MODEL_HPP
#define MODEL_HPP

#include "edges.hpp"
#include "error.hpp"
#include "screen.hpp"
#include "transform.hpp"
#include "transformMeta.hpp"
#include "vector2d.hpp"
#include "vector3d.hpp"

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_MODEL \
    {               \
    }

struct model_t {
    vector3d_t* vertices;
    edge_t* edges;
    int verticesAmount;
    int edgesAmount;
};

err_t loadModel(model_t* model, const char *filename);

err_t renderModel(const model_t* model, const screen_t& screen);

err_t transformModel(model_t* model, const transformMeta_t& transformMeta);

err_t dumpModel(const model_t* model, const char* filename);

void deleteModel(model_t *model);

#endif
