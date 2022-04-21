
file(GLOB LIB_SOURCE_FILES set/src/*.cpp)
file(GLOB LIB_HEADERS_FILES /include/*)
add_library(mySet STATIC "src/BaseCollection.cpp")
target_include_directories(mySet PUBLIC include)
add_subdirectory(unit_tests)