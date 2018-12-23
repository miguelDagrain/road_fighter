cmake_minimum_required(VERSION 3.8)
project(road_fighter)

set(CMAKE_INSTALL_PREFIX  "${PROJECT_SOURCE_DIR}")

#laat alle include searches #inlude "" beginnen vanuit root directory
set(CMAKE_CXX_FLAGS -I${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(roadfighter)
add_subdirectory(roadfighter_GUI)
add_subdirectory(app)



