
#include "roadfighter/include/Fuelcar.h"


/**
 * @brief basis constructor van een fuelcar.
 */
RF::Fuelcar::Fuelcar() = default;

/**
 * @brief destructor van een fuelcar.
 */
RF::Fuelcar::~Fuelcar() = default;

/**
 * @brief constructor van een fuelcar met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van de fuelcar.
 * @param entitySize grootte van de feulcar.
 * @param movement beweging van de feulcar.
 */
RF::Fuelcar::Fuelcar(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}

