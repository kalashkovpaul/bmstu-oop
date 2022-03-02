#include "read.hpp";
#include "global.hpp";
#include "execute.hpp";

err_t readLoad() {
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}

err_t readSave() {
    // TODO
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}

err_t readTransform() {
    // TODO
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}

err_t readRender() {
    // TODO
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}

err_t readDelete() {
    // TODO
    command_data_t command_data = { .filename = filename };
    return execute(LOAD_MODEL, command_data);
}