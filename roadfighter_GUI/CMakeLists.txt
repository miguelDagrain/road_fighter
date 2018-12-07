

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/roadfighter)

add_executable(game main.cpp Transformation.cpp Transformation.h)

target_link_libraries(game roadfighter ${SFML_LIBRARIES})