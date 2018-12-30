
#include <roadfighter/include/Racer.h>

#include "roadfighter/include/Racer.h"

RF::Racer::Racer() = default;

RF::Racer::~Racer() = default;

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
    specialActionDuration = 400;
}


void RF::Racer::update() {

    if(specialActionDuration == 0) {

        entityLocation += movement;

    }else{

        entityLocation += movement*2;

        --specialActionDuration;
    }

}

void RF::Racer::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
}


void RF::Racer::checkIfInWorld()
{
    //racers blijven in het spel
}