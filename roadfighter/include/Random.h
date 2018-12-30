

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H

#include <memory>
#include <random>

#include "roadfighter/include/World.h"

namespace RF {

    class Random {
    public:

        static std::shared_ptr<Random > &getInstance();

        int getIntCar();

        int getRandomInt();

        double getDoubleOnRoad();

        double getDoubleOnNextPiece();

    private:

        Random();

        static std::shared_ptr<Random > instance;

        std::random_device randomizer;
        std::default_random_engine engine;

    };

}

#endif //ROAD_FIGHTER_RANDOM_H
