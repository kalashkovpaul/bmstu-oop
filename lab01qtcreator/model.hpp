#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>

#include "vector3d.hpp"
#include "vector2d.hpp"
#include "screen.hpp"
#include "edges.hpp"
#include "error.hpp"
#include "transformMeta.hpp"
#include "transform.hpp"

#define EMPTY_MODEL {}
typedef struct {
    std::vector<vector3d_t> vertices;
    std::vector<edge_t> edges;
} model_t;

err_t loadModel(model_t *model, std::string &filename);

err_t renderModel(const model_t *model, const screen_t *screen);

err_t transformModel(model_t *model, const transformMeta_t *transformMeta);

#endif
