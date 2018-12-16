

#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <memory>

#include "roadfighter/include/World.h"

namespace RF {
    namespace Factory {

        template<typename Tresult, typename... Targs>
        class BaseFactory {
        public:
            BaseFactory() = default;

            virtual ~BaseFactory() = default;

            virtual Tresult createEntity(Targs... args) = 0;

        };


        class BulletFactory : public BaseFactory<std::shared_ptr<Bullet > > {
        public:
            BulletFactory() = default;

            std::shared_ptr<Bullet > createEntity() final;

            std::shared_ptr<Bullet > createEntity(location &entityLocation);
        };


        class FuelcarFactory : public BaseFactory<std::shared_ptr<Fuelcar > > {
        public:
            FuelcarFactory() = default;

            std::shared_ptr<Fuelcar > createEntity() final;
        };


    class PassingcarFactory : public BaseFactory<std::shared_ptr<Passingcar > > {
        public:
            PassingcarFactory() = default;

            std::shared_ptr<Passingcar > createEntity() final;
        };

    class PlayerFactory : public BaseFactory<std::shared_ptr<Player >> {
        public:
            PlayerFactory() = default;

            std::shared_ptr<Player > createEntity() final;
        };

    class RacerFactory : public BaseFactory<std::shared_ptr<Racer > >
        {
        public:
            RacerFactory() = default;

            std::shared_ptr<Racer > createEntity() final;
        };

    class WorldFactory : public BaseFactory<std::shared_ptr<World > >
        {
        public:
            WorldFactory() = default;

            std::shared_ptr<World > createEntity() final;
        };

    }
}
#endif //ROAD_FIGHTER_ENTITYFACTORY_H
