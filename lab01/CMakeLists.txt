cmake_minimum_required(VERSION 3.8)
project(oopLab01)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CXX g++)
set(LIB_SOURCE_FILES src/error.cpp src/execute.cpp src/model.cpp src/read.cpp src/vector3d.cpp)
set(LIB_HEADERS_FILES include/command.hpp include/edges.hpp include/error.hpp include/execute.hpp
include/global.hpp include/model.hpp include/read.hpp include/vector3d.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -Wvla -Iinclude -Wfloat-equal -pthread -Wpedantic -Wextra")


add_library(calculations STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(app src/main.cpp)
target_link_libraries(app calculations)
