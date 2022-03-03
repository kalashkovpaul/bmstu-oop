#include "read.hpp"

err_t readLoad() {
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}

err_t readSave() {
    // TODO
    command_data_t command_data = { filename, &screen, &transformMeta};
    return execute(LOAD_MODEL, command_data);
}

err_t readTransform() {
    command_data_t command_data = { filename, &screen, &transformMeta};
    return execute(TRANSFORM_MODEL, command_data);
}

err_t readRender() {
    command_data_t command_data = { filename, &screen, &transformMeta};
    return execute(RENDER_MODEL, command_data);
}

err_t readDelete() {
    // TODO
    command_data_t command_data = { filename, &screen, &transformMeta};
    return execute(LOAD_MODEL, command_data);
}
