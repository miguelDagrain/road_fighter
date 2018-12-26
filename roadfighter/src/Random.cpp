
#include <roadfighter/include/Random.h>

#include "roadfighter/include/Random.h"

namespace RF {
    std::shared_ptr<RF::Random > RF::Random::instance = nullptr;
}


std::shared_ptr<RF::Random > &RF::Random::getInstance()
{
    if(instance == nullptr){

        instance = std::shared_ptr<RF::Random >(this);
    }

    return instance;
}

long RF::Random::getIntNumber() {

    std::default_random_engine engine;
    std::uniform_int_distribution<int > distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    return distribution(engine);
}
