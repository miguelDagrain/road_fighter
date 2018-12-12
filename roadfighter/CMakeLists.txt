#add_library(Roadfighter_include
#                        Bullet.h Bullet.cpp
#                        Entity.h Entity.cpp
#                        Fuelcar.h Fuelcar.cpp
#                        Passingcar.h Passingcar.cpp
#                        Player.h Player.cpp
#                        Racer.h Racer.cpp
#                        World.h World.cpp)

add_library(roadfighter
        PlaneLocation.cpp
        Bullet.cpp
        Entity.cpp
        Fuelcar.cpp
        Passingcar.cpp
        Player.cpp
        Racer.cpp
        World.cpp
        EntityFactory.cpp
        RoadfighterError.cpp)

target_include_directories(roadfighter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})