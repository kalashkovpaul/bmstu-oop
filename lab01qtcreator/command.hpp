#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

#include "screen.hpp"
#include "transformMeta.hpp"

typedef enum {
    LOAD_MODEL,
    SAVE_MODEL,
    TRANSFORM_MODEL,
    RENDER_MODEL,
    DELETE_MODEL
} command_t;

typedef struct {
    std::string &filename;
    screen_t *screen;
    transformMeta_t *transformMeta;
} command_data_t; 

#endif
