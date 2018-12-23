#include "roadfighter/include/Racer.h"

RF::Racer::Racer() = default;

RF::Racer::~Racer() = default;

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize) : Entity(entityLocation, entitySize) {

}

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}
