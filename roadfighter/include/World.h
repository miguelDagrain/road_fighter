

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include <algorithm>
#include <vector>

#include "roadfighter/include/ObserverWorld.h"
#include "roadfighter/include/Entity.h"
#include "roadfighter/include/Player.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/RoadfighterError.h"



namespace RF {

    extern double endOfRoad;

    class World : public Entity{

    public:
        World();

        ~World() override;

        void addObject(std::shared_ptr<Entity > newbornObject) final;

        void removeObject(std::shared_ptr<Entity > deadObject) final;



        void update() final;

        void checkIfOnRoad() final;

        void checkIfCollided(const std::shared_ptr<Entity > &other) final;

        void correctPosition(PlaneLocation correctionVector) final;

        //deze member zet enkel de movement voor de player
        void accelerate(movementVector &acceleration) final;

        void attackAction(RF::Entity &world) final;

        void draw() final;

        void setObserver(std::shared_ptr<RF::ObserverWorld > &&observerPtr) override;

    private:
        //deze member heeft geen zin voor de composite class
        void checkIfInWorld() final;

        //deze member heeft geen zin voor de composite class
        bool hasCrashed() const final;

        //deze member heeft geen zin voor de composite class
        const location &getLocation() const final;

        //deze member heeft geen zin voor de composite class
        const size &getSize() const final;

        //deze member heeft geen zin voor de composite class
        const movementVector  &getMovement() const final;

        std::vector<std::shared_ptr<Entity > > livingObjects;
    };

}

#endif //ROAD_FIGHTER_WORLD_H
