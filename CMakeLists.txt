cmake_minimum_required(VERSION 3.13)
project(fillit C)      # project name
set(CMAKE_C_STANDARD 99)
add_compile_options()#-Wall -Werror -Wextra) # flags
###find_library(OPEN_GL OpenGl)
###find_library(APP_KIT AppKit)
include_directories(./ ./libft/includes)  #directory with headers
###link_directories(/usr/local/lib ./libft)
###link_libraries(mlx)
FILE(GLOB LIBFT_SRCS ./libft/*.c)  # ADD LIBFT as sources
add_executable(Fillit ${LIBFT_SRCS} fillit.h fillit.c int2tetra.c)
# all project-c-files here

###target_link_libraries(Fillit ${OPEN_GL} ${APP_KIT})  # LINK libraries
#target_link_libraries(Fillit "path to libft.a")
#${LIBFT}