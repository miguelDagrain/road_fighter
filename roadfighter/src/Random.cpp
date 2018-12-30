
#include <roadfighter/include/Random.h>

#include "roadfighter/include/Random.h"

namespace RF {
    std::shared_ptr<RF::Random > RF::Random::instance = nullptr;
}


std::shared_ptr<RF::Random > &RF::Random::getInstance()
{
    if(instance == nullptr){

        auto random = new Random();

        instance = std::shared_ptr<RF::Random >(random);
    }

    return instance;
}

int RF::Random::getIntCar()
{
    std::uniform_int_distribution<int > distribution(0, 8);

    return distribution(engine);
}


int RF::Random::getRandomInt() {
    std::uniform_int_distribution<int > distribution(0, 10);

    return distribution(engine);
};


double RF::Random::getDoubleOnRoad()
{
    //de -0.4 is om geen auto over de witte lijn te creeren
    std::uniform_real_distribution<double > distribution(-RF::endOfRoad, RF::endOfRoad-0.4);

    return distribution(engine);
}

double RF::Random::getDoubleOnNextPiece()
{
    std::uniform_real_distribution<double > distribution(-6, -3.4);

    return distribution(engine);
}

RF::Random::Random()
{
    engine = std::default_random_engine(randomizer());
}

