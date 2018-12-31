#include "roadfighter/include/Finish.h"

RF::Finish::Finish() = default;

RF::Finish::~Finish() = default;

RF::Finish::Finish(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement)  :
Road(entityLocation, entitySize, movement)
{
}