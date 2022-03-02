#pragma once

#include <string>

typedef enum {
    LOAD_MODEL,
    SAVE_MODEL,
    TRANSFORM_MODEL,
    RENDER_MODEL,
    DELETE_MODEL
} command_t;

typedef struct {
    const std::string &filename;
} command_data_t; 