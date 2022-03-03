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

struct model_t {
    std::vector<vector3d_t> vertices;
    std::vector<edge_t> edges;
};

err_t loadModel(model_t& model, std::string &filename);

err_t renderModel(const model_t& model, const screen_t& screen);

err_t transformModel(model_t& model, const transformMeta_t& transformMeta);

err_t dumpModel(const model_t& model, const std::string &filename);

#endif
