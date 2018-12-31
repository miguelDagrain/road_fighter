
#include <roadfighter/include/Road.h>

#include "roadfighter/include/Road.h"

RF::Road::Road() = default;

RF::Road::~Road() = default;

RF::Road::Road(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
}

void RF::Road::checkIfInWorld()
{
    //-9 omdat we een vloeiend overgang willen creeren en dus een extra stuk weg moeten kunnen generen in de wereld
    if(this->getLocation().second > 3 || this->getLocation().second < -9){
        crashed = true;
    }
}

void RF::Road::checkIfOnRoad()
{
}

void RF::Road::checkIfCollided(const std::shared_ptr<Entity > &other)
{
}