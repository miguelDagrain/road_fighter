

add_library(FILES_GAME_LOGIC STATIC
        src/PlaneLocation.cpp
        src/Bullet.cpp
        src/Entity.cpp
        src/Fuelcar.cpp
        src/Passingcar.cpp
        src/Player.cpp
        src/Racer.cpp
        src/Road.cpp
        src/World.cpp
        src/RoadfighterError.cpp
        src/Random.cpp
        src/SemiObserverWorld.cpp)

set(HEADER_FILES_GAME_LOGIC
        include/PlaneLocation.h
        include/Bullet.h
        include/Entity.h
        include/Fuelcar.h
        include/Passingcar.h
        include/Player.h
        include/Racer.h
        include/Road.h
        include/World.h
        include/RoadfighterError.h
        include/Random.h
        include/SemiObserverWorld.h
        PARENT_SCOPE)


target_include_directories(FILES_GAME_LOGIC PUBLIC ${HEADER_FILES_GAME_LOGIC})

#
#install(TARGETS FILES_GAME_LOGIC DESTINATION ${PROJECT_SOURCE_DIR}/build/lib/logic)
#
#install(FILES include DESTINATION ${PROJECT_SOURCE_DIR}/build/include/logic)
#
