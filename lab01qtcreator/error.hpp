#ifndef ERROR_HPP
#define ERROR_HPP

enum err_t {
    NONE,
    WRONG_USAGE,
	CANT_OPEN_FILE,
	INVALID_FILE_FORMAT,
	ALLOC_FAIL,
	WRONG_COMMAND
};

void printMessage(err_t error);

void printOptions();

#endif
