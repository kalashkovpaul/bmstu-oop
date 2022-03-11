#pragma once

#include "command.hpp"
#include "error.hpp"
#include "model.hpp"

err_t execute(command_t command, const command_data_t &commandData);

