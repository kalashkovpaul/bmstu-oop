#include <iostream>
#include <string>
#include <QApplication>
#include <QWidget>

#include "MainWindow.hpp"
#include "execute.hpp"
#include "global.hpp"
#include "read.hpp"
#include "error.hpp"

std::string filename = "";

int main(int argc, char *argv[]) {
    if (argc != 2) {
		printMessage(WRONG_USAGE);
		return EXIT_FAILURE;
	}

	filename = std::string(argv[1]);

	err_t error = readLoad();
	if (error) {
		printMessage(error);
		return EXIT_FAILURE;
	}

	printOptions();

	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.show();
	
	app.exec();

    return EXIT_SUCCESS;
}