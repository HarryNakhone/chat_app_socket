cmake_minimum_required(VERSION 3.23)
project(c_socket C)

set(CMAKE_C_STANDARD 99)



find_path(TheHeaderFile socketutil.h
        PATHS /home/hrry/socket_util)

find_library(TheLibrary
        NAMES socket_util
        PATHS /home/hrry/socket_util/cmake-build-debug)

add_executable(c_socket main.c)

include_directories(${TheHeaderFile})
target_link_libraries(${PROJECT_NAME} ${TheLibrary})