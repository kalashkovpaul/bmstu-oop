#include "execute.hpp"

err_t execute(command_t command, const command_data_t &commandData) {
    static model_t model = EMPTY_MODEL;
    err_t error = NONE;
    switch (command) {
    case LOAD_MODEL:
        error = loadModel(model, commandData.filename);
        break;
    case SAVE_MODEL:
		// error = dump_model(&model, command_data->filename);
		break;
	case TRANSFORM_MODEL:
		// error = transform_model(&model, command_data->transform_meta);
		break;
	case RENDER_MODEL:
		// error = render_model(&model, command_data->screen);
		break;
	case DELETE_MODEL:
		// delete_model(&model);
		break;
	default:
		error = WRONG_COMMAND;
		break;
    }
    return error;
}