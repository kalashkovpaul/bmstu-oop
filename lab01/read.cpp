#include "read.hpp"
#include "execute.hpp"
#include "global.hpp"

err_t readLoad()
{
    command_data_t command_data = { filename, screen, transformMeta };
    return execute(LOAD_MODEL, command_data);
}

err_t readSave()
{
    command_data_t command_data = { filename, screen, transformMeta };
    return execute(SAVE_MODEL, command_data);
}

err_t readTransform()
{
    command_data_t command_data = { filename, screen, transformMeta };
    return execute(TRANSFORM_MODEL, command_data);
}

err_t readRender()
{
    command_data_t command_data = { filename, screen, transformMeta };
    return execute(RENDER_MODEL, command_data);
}

err_t readDelete()
{
    command_data_t command_data = { filename, screen, transformMeta };
    return execute(DELETE_MODEL, command_data);
}
