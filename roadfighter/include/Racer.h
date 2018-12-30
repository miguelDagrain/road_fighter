

#ifndef ROAD_FIGHTER_RACER_H
#define ROAD_FIGHTER_RACER_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class Racer : public Entity {

    public:
        Racer();

        ~Racer() override;

        Racer(location &entityLocation, size &entitySize, movementVector &movement);

        void update() final;

        void checkIfCollided(const std::shared_ptr<RF::Entity> &other) final;

        void checkIfInWorld() final;
    };

}

#endif //ROAD_FIGHTER_RACER_H
