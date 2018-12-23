

#ifndef ROAD_FIGHTER_FUELCAR_H
#define ROAD_FIGHTER_FUELCAR_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Fuelcar : public Entity {

    public:
        Fuelcar();

        ~Fuelcar() override;

        Fuelcar(location &entityLocation, size &entitySize);

        Fuelcar(location &entityLocation, size &entitySize, movementVector &movement);
    };

}

#endif //ROAD_FIGHTER_FUELCAR_H
