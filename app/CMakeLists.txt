
# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)



include_directories(
        ${HEADER_FILES_GAME_LOGIC}
        ${HEADER_FILES_GAME_GUI}
        ${SFML_INCLUDE_DIR}
)

#Maak executable aan
add_executable(game main.cpp)

#target_include_directories(game PUBLIC ${HEADER_FILES_GAME_LOGIC} ${HEADER_FILES_GAME_GUI} ${SFML_INCLUDE_DIR})

#Link alle nodige files
target_link_libraries(game ${FILES_GAME_LOGIC} ${FILES_GAME_GUI} ${SFML_LIBRARIES})

install(TARGETS game RUNTIME DESTINATION /build)