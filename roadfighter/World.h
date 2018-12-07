

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include <Bullet.h>
#include <Fuelcar.h>
#include <Passingcar.h>
#include <Player.h>
#include <Racer.h>

#include <vector>


namespace RF {

    class World : public Entity{



    private:
        std::vector<Entity *> existingObjects;
    };

}

#endif //ROAD_FIGHTER_WORLD_H
