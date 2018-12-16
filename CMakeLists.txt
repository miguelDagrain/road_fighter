cmake_minimum_required(VERSION 3.8)
project(road_fighter)

#laat alle include searches #inlude "" beginnen vanuit root directory
set(CMAKE_CXX_FLAGS -I${PROJECT_SOURCE_DIR})

set(CMAKE_INSTALL_PREFIX  "${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(roadfighter)
add_subdirectory(roadfighter_GUI)

#Maak executable aan
add_executable(game main.cpp)

#Link alle nodige files
target_link_libraries(game FILES_GAME_LOGIC FILES_GAME_GUI ${SFML_LIBRARIES})

install(TARGETS game RUNTIME DESTINATION build)