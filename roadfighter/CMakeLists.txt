

add_library(FILES_GAME_LOGIC STATIC
        src/PlaneLocation.cpp
        src/Bullet.cpp
        src/Entity.cpp
        src/Fuelcar.cpp
        src/Passingcar.cpp
        src/Player.cpp
        src/Racer.cpp
        src/World.cpp
        src/EntityFactory.cpp
        src/RoadfighterError.cpp)

install(TARGETS FILES_GAME_LOGIC ARCHIVE DESTINATION build/lib/logic)


target_include_directories(FILES_GAME_LOGIC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
