

#ifndef ROAD_FIGHTER_RACER_H
#define ROAD_FIGHTER_RACER_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Racer : public Entity {

    public:
        Racer();

        ~Racer() override;

        Racer(location &entityLocation, size &entitySize);

        Racer(location &entityLocation, size &entitySize, movementVector &movement);
    };

}

#endif //ROAD_FIGHTER_RACER_H
