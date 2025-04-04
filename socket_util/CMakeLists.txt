cmake_minimum_required(VERSION 3.23)
project(socket_util C)

set(CMAKE_C_STANDARD 99)

add_library(socket_util STATIC socketutil.c)
