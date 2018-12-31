

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H

#include "roadfighter/include/Entity.h"
#include "roadfighter/include/ObserverWorld.h"


namespace RF {

    class Passingcar : public Entity{

    public:
        Passingcar();

        ~Passingcar() override;

        Passingcar(location &entityLocation, size &entitySize, movementVector &movement);

        void checkIfCollided(const std::shared_ptr<RF::Entity> &other) override;
    };

}

#endif //ROAD_FIGHTER_PASSINGCAR_H
