

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

    //De lijn wordt ergens getrokken zodat het overeenkomt met de achtergrond. Deze verhoudingen zijn niet de grootte
    //van het scherm maar van de gebruikte afbeelding.
    double lineEndOfRoad = (156/294.0)*4;

    class World : public Entity{

    public:
        World() = default;

        void addObject(std::shared_ptr<Entity > newbornObject) final;

        void removeObject(std::shared_ptr<Entity > deadObject) final;



        void update() final;

        void checkIfOnRoad(const double& sideline) final;

        void checkIfCollided(std::shared_ptr<Entity > other) final;

        void checkOnCollision() final;

        void correctPosition(PlaneLocation& correctionVector) final;


        std::vector<std::shared_ptr<Entity > >::const_iterator begin() const final;

        std::vector<std::shared_ptr<Entity > >::const_iterator end() const final;

    private:

        //deze member heeft geen zin voor de composite class
        bool hasCrashed() const final;

        //deze member heeft geen zin voor de composite class
        const location &getLocation() const final;

        //deze member heeft geen zin voor de composite class
        const size &getSize() const final;

        //deze member heeft geen zin voor de composite class
        const movementVector  &getMovement() const final;

        //deze member heeft geen zin voor de composite class
        void setMovement(movementVector &newVelocity) final;

        std::vector<std::shared_ptr<Entity > > livingObjects;
    };

}

#endif //ROAD_FIGHTER_WORLD_H
