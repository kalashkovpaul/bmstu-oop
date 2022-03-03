#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

#include "screen.hpp"
#include "transformMeta.hpp"

enum command_t {
    LOAD_MODEL,
    SAVE_MODEL,
    TRANSFORM_MODEL,
    RENDER_MODEL
};

struct command_data_t {
    std::string &filename;
    screen_t& screen;
    transformMeta_t& transformMeta;
};

#endif
