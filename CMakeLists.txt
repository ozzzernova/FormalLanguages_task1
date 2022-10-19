cmake_minimum_required(VERSION 3.9)
project(FormalLang)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./googletest)
set(LIBRARIES
        gtest
        pthread)

add_executable(Tests src/gtests.cpp include/lang.h src/lang.cpp)
add_executable(Main main.cpp include/lang.h src/lang.cpp)
target_link_libraries(Tests gtest)