cmake_minimum_required(VERSION 3.17)
project(pipex C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(libft/include)

add_subdirectory(libft)

add_executable(pipex
        include/pipex.h
        src/main.c)

target_link_libraries(pipex ft)
