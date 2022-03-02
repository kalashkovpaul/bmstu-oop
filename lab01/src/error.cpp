#include "error.hpp"
#include "global.hpp"

#include <iostream>


void printMessage(err_t error) {
	switch (error) {
	case NONE:
		break;
	case WRONG_USAGE:
        std::cerr << "Correct usage: ./app <filename>" << std::endl;
		break;
	case CANT_OPEN_FILE:
		std::cerr << filename << ": cannot open the file" << std::endl;
		break;
	case INVALID_FILE_FORMAT:
        std::cerr << filename << ": Invalid file format" << std::endl;
		break;
	case ALLOC_FAIL:
		std::cerr << "Memory allocation failed" << std::endl;
		break;
	case WRONG_COMMAND:
		std::cerr << "Command not found" << std::endl;
		break;
	}
}