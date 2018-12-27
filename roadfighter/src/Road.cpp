
#include "roadfighter/include/Road.h"

RF::Road::Road() = default;

RF::Road::~Road() = default;

RF::Road::Road(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
}
