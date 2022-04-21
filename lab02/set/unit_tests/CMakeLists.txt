add_executable(mySetTest src/main_test.cpp)

target_include_directories(mySetTest PUBLIC include)

target_link_libraries(mySetTest mySet GTest::Main gcov)

add_test(NAME mySetTest COMMAND mySetTest)