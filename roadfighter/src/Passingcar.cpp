

#include <include/Passingcar.h>

#include "roadfighter/include/Passingcar.h"

RF::Passingcar::Passingcar(RF::location &entityLocation, RF::size &entitySize) : Entity(entityLocation, entitySize)
{

}

RF::Passingcar::Passingcar(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}
