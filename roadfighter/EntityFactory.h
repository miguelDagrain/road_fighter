

#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <World.h>

namespace RF {
    namespace Factory {

        template<typename Tresult, typename... Targs>
        class BaseFactory {
        public:
            virtual ~BaseFactory() = default;

            virtual Tresult createEntity(Targs... args) = 0;

        };


        class BulletFactory : public BaseFactory<Bullet *> {
        public:
            BulletFactory() = default;

            Bullet *createEntity() final;

        };


        class FuelcarFactory : public BaseFactory<Fuelcar *> {
        public:
            FuelcarFactory() = default;

            Fuelcar *createEntity() final;
        };


        class PassingcarFactory : public BaseFactory<Passingcar *> {
        public:
            PassingcarFactory() = default;

            Passingcar *createEntity() final;
        };

        class PlayerFactory : public BaseFactory<Player *> {
        public:
            PlayerFactory() = default;

            Player *createEntity() final;
        };

        class RacerFactory : public BaseFactory<Racer *>
        {
        public:
            RacerFactory() = default;

            Racer *createEntity() final;
        };

        class WorldFactory : public BaseFactory<World *>
        {
        public:
            WorldFactory() = default;

            World *createEntity() final;
        };

    }
}
#endif //ROAD_FIGHTER_ENTITYFACTORY_H
