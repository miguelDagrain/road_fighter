

#include <include/Fuelcar.h>

#include "roadfighter/include/Fuelcar.h"

RF::Fuelcar::Fuelcar(RF::location &entityLocation, RF::size &entitySize) : Entity(entityLocation, entitySize)
{

}

RF::Fuelcar::Fuelcar(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}
