#include "roadfighter/include/Finish.h"

/**
 * @brief basis constructor van een eindstuk.
 */
RF::Finish::Finish() = default;

/**
 * @brief basis destructor van een eindstuk.
 */
RF::Finish::~Finish() = default;

/**
 * @brief constructor van een eindstuk met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van het eindstuk.
 * @param entitySize grootte van het eindstuk.
 * @param movement beweging van het eindstuk.
 */
RF::Finish::Finish(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement)  :
Road(entityLocation, entitySize, movement)
{
}