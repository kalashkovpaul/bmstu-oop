#pragma once

#include <vector>
#include <string>

#include "vector3d.hpp"
#include "edges.hpp"
#include "error.hpp"

#define EMPTY_MODEL {}
typedef struct {
    std::vector<vector3d_t> vertices;
    std::vector<edge_t> edges;
} model_t;

err_t loadModel(model_t &model, const std::string &filename);
