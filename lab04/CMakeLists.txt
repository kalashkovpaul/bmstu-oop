cmake_minimum_required(VERSION 3.14)
project(lab04)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCES
    main.cpp
    Cab/Cab.cpp
    CabDoors/CabDoors.cpp
    ControlPanel/ControlPanel.cpp
    Direction/Direction.cpp
    Elevator/Elevator.cpp
    Logger/Logger.cpp
    MainWindow/mainwindow.cpp
)

set(HEADERS
    Cab/Cab.hpp
    CabDoors/CabDoors.hpp
    ControlPanel/ControlPanel.hpp
    Direction/Direction.hpp
    Elevator/Elevator.hpp
    Logger/Logger.hpp
    MainWindow/mainwindow.hpp
)

add_executable(lab04 ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)