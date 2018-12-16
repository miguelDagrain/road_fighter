

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/roadfighter)

add_library(FILES_GAME_GUI STATIC
        src/Transformation.cpp
        src/BulletSFML.cpp
        src/FuelcarSFML.cpp
        src/PassingcarSFML.cpp
        src/PlayerSFML.cpp
        src/RacerSFML.cpp)


install(TARGETS FILES_GAME_GUI ARCHIVE DESTINATION build/lib/gui)

target_include_directories(FILES_GAME_GUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})