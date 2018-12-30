

#ifndef ROAD_FIGHTER_PLAYER_H
#define ROAD_FIGHTER_PLAYER_H


#include "roadfighter/include/Entity.h"


namespace RF {

    class Player: public Entity {

    public:
        Player();

        ~Player() override;

        Player(location &entityLocation, size &entitySize, movementVector &movement);

        void update() final;

        void correctPosition(PlaneLocation correctionVector) final;

        void checkIfCollided(const std::shared_ptr<Entity > &other) final;

    };

}

#endif //ROAD_FIGHTER_PLAYER_H
