

#ifndef ROAD_FIGHTER_RACER_H
#define ROAD_FIGHTER_RACER_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Racer : public Entity {

    public:
        Racer() = default;

        Racer(location& entityLocation, size& entitySize);

    };

}

#endif //ROAD_FIGHTER_RACER_H
