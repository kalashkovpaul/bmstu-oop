#include "execute.hpp"

err_t execute(command_t command, const command_data_t& commandData)
{
    static model_t model = EMPTY_MODEL;
    err_t error = NONE;
    switch (command) {
    case LOAD_MODEL:
        error = loadModel(&model, commandData.filename);
        break;
    case SAVE_MODEL:
        error = dumpModel(&model, commandData.filename);
        break;
    case TRANSFORM_MODEL:
        error = transformModel(&model, commandData.transformMeta);
        break;
    case RENDER_MODEL:
        error = renderModel(&model, commandData.screen);
        break;
    case DELETE_MODEL:
        deleteModel(&model);
        break;
    default:
        error = WRONG_COMMAND;
        break;
    }
    return error;
}
