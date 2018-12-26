

#ifndef ROAD_FIGHTER_RANDOM_H
#define ROAD_FIGHTER_RANDOM_H

#include <memory>
#include <random>

namespace RF {

    class Random {
    public:

        std::shared_ptr<Random > &getInstance();

        long getIntNumber();

    private:

        static std::shared_ptr<Random > instance;

    };

}

#endif //ROAD_FIGHTER_RANDOM_H
