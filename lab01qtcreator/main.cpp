#include <iostream>
#include <string>
#include <QApplication>
#include <QWidget>

#include "execute.hpp"
#include "global.hpp"
#include "MainWindow.hpp"
#include "read.hpp"

std::string filename = "";
screen_t screen = { 10, 10, 5, 90, nullptr };
transformMeta_t transformMeta;

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
    mainWindow.move(100, 100);
    mainWindow.setFixedSize(900, 900);
    mainWindow.initCanvas();
    screen.canvas = mainWindow.canvas;
    mainWindow.show();

    app.exec();

    return EXIT_SUCCESS;
}
