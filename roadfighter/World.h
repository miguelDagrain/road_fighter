

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include <Bullet.h>
#include <Fuelcar.h>
#include <Passingcar.h>
#include <Player.h>
#include <Racer.h>
#include <RoadfighterError.h>

#include <algorithm>
#include <vector>


namespace RF {

    class World : public Entity{

    public:
        World() = default;

        void addObject(std::shared_ptr<Entity > newbornObject) final;

        void removeObject(std::shared_ptr<Entity > deadObject) final;

        void update() final;

        void correctPosition(PlaneLocation& correctionVector) final;

        //deze member heeft geen zin voor de composite class
        const location &getLocation() const final;

        //deze member heeft geen zin voor de composite class
        const size &getSize() const final;

        //deze member heeft geen zin voor de composite class
        const movementVector  &getMovement() const final;

        //deze member heeft geen zin voor de composite class
        void setMovement(movementVector &newVelocity) final;
    private:
        std::vector<std::shared_ptr<Entity > > livingObjects;
    };

}

#endif //ROAD_FIGHTER_WORLD_H
