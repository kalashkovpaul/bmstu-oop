#include <iostream>
#include <string>
#include "execute.hpp"
#include "global.hpp"
#include "read.hpp"
#include "error.hpp"

std::string filename = "";

int main(int argc, char *argv[]) {
    if (argc != 2) {
		fputs("Usage: wm3dv <filename>\n", stderr);
		return EXIT_FAILURE;
	}

	filename = std::string(argv[1]);

	err_t error = readLoad();
	if (error) {
		printMessage(error);
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}