cmake_minimum_required(VERSION 3.10)
project(road_fighter)

set(CMAKE_CXX_STANDARD 11)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

set(SOURCE_FILES main.cpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

add_executable(road_fighter ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(road_fighter ${SFML_LIBRARIES})

#INSTALL(TARGETS plotter_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)