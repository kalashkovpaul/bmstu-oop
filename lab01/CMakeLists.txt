cmake_minimum_required(VERSION 3.8)
project(oopLab01)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CXX g++)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(LIB_SOURCE_FILES src/error.cpp src/execute.cpp src/model.cpp src/read.cpp 
src/vector3d.cpp src/edges.cpp src/MainWindow.cpp src/Canvas.cpp)
set(LIB_HEADERS_FILES include/command.hpp include/edges.hpp include/error.hpp 
include/execute.hpp include/global.hpp include/model.hpp include/read.hpp 
include/vector3d.hpp include/MainWindow.hpp include/Canvas.hpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Wall -Werror -pedantic -Wvla -Iinclude -Wfloat-equal -pthread -Wpedantic -Wextra")


add_library(calculations STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Qt5 REQUIRED
    Core
    Widgets
    Gui
    OpenGL
    OpenGLExtensions
)

add_executable(app src/main.cpp)

qt5_use_modules(app Core Widgets)

target_link_libraries(app calculations)
