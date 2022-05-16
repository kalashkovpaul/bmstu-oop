cmake_minimum_required(VERSION 3.8)
project(homework_2_5)
enable_language(C)
enable_language(CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CXX g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -Wvla -Iinc -Wfloat-equal -pthread -Wpedantic -Wextra -lgcov")
add_compile_options("--coverage")
add_link_options("--coverage")

enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(set)

add_executable(app src/main.cpp)

target_link_libraries(app mySet gcov)
