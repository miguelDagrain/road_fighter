

#ifndef ROAD_FIGHTER_BULLET_H
#define ROAD_FIGHTER_BULLET_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Bullet: public Entity {

    public:
        Bullet() = default;

        Bullet(location& entityLocation, size& entitySize);


    };

}

#endif //ROAD_FIGHTER_BULLET_H
