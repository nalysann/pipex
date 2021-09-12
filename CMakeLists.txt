cmake_minimum_required(VERSION 3.20)
project(pipex C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(libft/include)

add_subdirectory(libft)

add_executable(pipex
        include/pipex.h
        src/pipex.c
        src/utils.c)

target_link_libraries(pipex ft)

add_executable(pipex_bonus
        include/pipex.h
        src/pipex_bonus.c
        src/utils.c)

target_link_libraries(pipex_bonus ft)
