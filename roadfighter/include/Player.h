

#ifndef ROAD_FIGHTER_PLAYER_H
#define ROAD_FIGHTER_PLAYER_H


#include "roadfighter/include/Entity.h"


namespace RF {

    class Player: public Entity {

    public:
        Player() = default;

        Player(location& entityLocation, size& entitySize);

        void attackAction(std::shared_ptr<Entity > world) final;
    };

}

#endif //ROAD_FIGHTER_PLAYER_H
