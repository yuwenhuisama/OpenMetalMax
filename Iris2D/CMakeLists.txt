cmake_minimum_required(VERSION 3.10)
project(Iris2D_Cherry_Spinach)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include/Common)
include_directories(./include/OpenGL)

aux_source_directory(. DIR_SRCS)
aux_source_directory(./src DIR_SRCS_MAIN)
aux_source_directory(./src/OpenGL DIR_SRCS_MAIN_OPENGL)

aux_source_directory(./include DIR_INCLUDES_MAIN)
aux_source_directory(./include/OpenGL DIR_INCLUDES_MAIN_OPENGL)
aux_source_directory(./include/Common DIR_INCLUDES_COMMON_OPENGL)

add_executable(main ${DIR_SRCS} ${DIR_SRCS_MAIN} ${DIR_SRCS_MAIN_OPENGL}
        ${DIR_INCLUDES_MAIN} ${DIR_INCLUDES_MAIN_OPENGL} ${DIR_INCLUDES_COMMON_OPENGL})
