cmake_minimum_required(VERSION 3.14)
project(minishelln C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(minishelln
        inc/minishell.h
        src/cd_builtin.c
        src/env_builtin.c
        src/ft_exe.c
        src/main.c src/echo_builtin.c src/echo_strsplit.c)

target_link_libraries(minishelln ${CMAKE_SOURCE_DIR}/libft/libft.a)