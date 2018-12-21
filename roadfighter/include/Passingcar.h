

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Passingcar : public Entity{

    public:
        Passingcar() = default;

        Passingcar(location &entityLocation, size &entitySize);

        Passingcar(location &entityLocation, size &entitySize, movementVector &movement);
    };

}

#endif //ROAD_FIGHTER_PASSINGCAR_H
