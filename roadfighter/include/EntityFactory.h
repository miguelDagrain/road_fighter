
#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <memory>

#include "roadfighter/include/World.h"

namespace RF {
    namespace Factory {

        template<typename Tresult>
        class BaseFactory {
        public:
            BaseFactory() = default;

            virtual ~BaseFactory() = default;

            template <typename... Targs>
            std::shared_ptr<Tresult > createEntity(Targs... args);

        };

        class BulletFactory : public BaseFactory<Bullet> {
        public:
            BulletFactory() = default;

            //ik weet dat dit niet de template createEntity van baseFactory niet overschrijft
            std::shared_ptr<Bullet > createEntity();

            std::shared_ptr<Bullet > createEntity(location &entityLocation, movementVector &movement);
        };


        class FuelcarFactory : public BaseFactory<Fuelcar> {
        public:
            FuelcarFactory() = default;

            std::shared_ptr<Fuelcar > createEntity();

            std::shared_ptr<Fuelcar > createEntity(location &entityLocation, movementVector &movement);
        };


        class PassingcarFactory : public BaseFactory<Passingcar> {
        public:
            PassingcarFactory() = default;

            std::shared_ptr<Passingcar > createEntity();

            std::shared_ptr<Passingcar > createEntity(location &entityLocation, movementVector &movement);
        };

        class PlayerFactory : public BaseFactory<Player> {
        public:
            PlayerFactory() = default;

            std::shared_ptr<Player > createEntity();

            std::shared_ptr<Player > createEntity(location &entityLocation, movementVector &movement);
        };

        class RacerFactory : public BaseFactory<Racer>
        {
        public:
            RacerFactory() = default;

            std::shared_ptr<Racer > createEntity();

            std::shared_ptr<Racer > createEntity(location &entityLocation, movementVector &movement);
        };


        class WorldFactory : public BaseFactory<World>
        {
        public:
            WorldFactory() = default;


            std::shared_ptr<World > createEntity();
        };

    }
}
#endif //ROAD_FIGHTER_ENTITYFACTORY_H