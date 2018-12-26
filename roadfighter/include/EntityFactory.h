
#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <memory>

#include "roadfighter/include/World.h"

namespace RF {

        class Factory {
        public:
            Factory() = default;

            virtual ~Factory() = default;

            template <typename Tresult>
            std::shared_ptr<Tresult > createEntity();

            std::shared_ptr<Bullet > createBullet(location &entityLocation, movementVector &movement);

            std::shared_ptr<Fuelcar > createFuelcar(location &entityLocation, movementVector &movement);

            std::shared_ptr<Passingcar > createPassingcar(location &entityLocation, movementVector &movement);

            std::shared_ptr<Player > createPlayer(location &entityLocation, movementVector &movement);

            std::shared_ptr<Racer > createRacer(location &entityLocation, movementVector &movement);
        };

}
#endif //ROAD_FIGHTER_ENTITYFACTORY_H