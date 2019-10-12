cmake_minimum_required(VERSION 3.13)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell src/main.c inc/minishell.h)

target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/libft/libft.a)