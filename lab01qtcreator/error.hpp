#ifndef ERROR_HPP
#define ERROR_HPP

#include "global.hpp"

typedef enum {
    NONE,
    WRONG_USAGE,
	CANT_OPEN_FILE,
	INVALID_FILE_FORMAT,
	ALLOC_FAIL,
	WRONG_COMMAND
} err_t;

void printMessage(err_t error);

void printOptions();

#endif
