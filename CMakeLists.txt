cmake_minimum_required(VERSION 3.13)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell src/main.c inc/minishell.h src/lists.c src/sort_files.c src/display_files.c src/dop_files.c)

target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/libft/libft.a)