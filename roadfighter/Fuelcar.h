

#ifndef ROAD_FIGHTER_FUELCAR_H
#define ROAD_FIGHTER_FUELCAR_H

#include "Entity.h"

namespace RF {

    class Fuelcar : public Entity {

    public:
        Fuelcar() = default;

        Fuelcar(location& entityLocation, size& entitySize);
    };

}

#endif //ROAD_FIGHTER_FUELCAR_H
