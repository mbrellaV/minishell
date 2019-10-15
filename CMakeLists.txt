cmake_minimum_required(VERSION 3.13)
project(minishell)

set(CMAKE_CXX_STANDARD 99)

add_executable(minishell src/main.c src/cd_builtin.c src/ft_exe.c inc/minishell.h )

target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/libft/libft.a)
