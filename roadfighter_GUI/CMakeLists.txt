

add_library(FILES_GAME_GUI STATIC
        src/Transformation.cpp
        src/BulletSFML.cpp
        src/FuelcarSFML.cpp
        src/PassingcarSFML.cpp
        src/PlayerSFML.cpp
        src/RacerSFML.cpp)

set(HEADER_FILES_GAME_GUI
        include/Transformation.h
        include/BulletSFML.h
        include/FuelcarSFML.h
        include/PassingcarSFML.h
        include/PlayerSFML.h
        include/RacerSFML.h
        PARENT_SCOPE)



target_include_directories(FILES_GAME_GUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#install(TARGETS FILES_GAME_GUI DESTINATION ${PROJECT_SOURCE_DIR}/build/lib/gui)
#
#install(FILES "${ITEM}" DESTINATION ${PROJECT_SOURCE_DIR}/build/include/gui)
#
