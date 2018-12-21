//
// Created by miguel on 02.12.18.
//

#include <include/Racer.h>

#include "roadfighter/include/Racer.h"

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize) : Entity(entityLocation, entitySize) {

}

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}
