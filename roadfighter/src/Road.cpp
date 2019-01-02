#include "roadfighter/include/Road.h"

/**
 * @brief basis constructor van een Road.
 */
RF::Road::Road() = default;

/**
 * @brief destructor van een Road.
 */
RF::Road::~Road() = default;

/**
 * @brief constructor van een Road met locatie, grootte, beweging.
 *
 * @param entityLocation locatie van de Road.
 * @param entitySize grootte van de Road.
 * @param movement beweging van de Road.
 */
RF::Road::Road(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
}

/**
 * @brief functie die controleert of de Road nog in de wereld ligt.
 */
void RF::Road::checkIfInWorld()
{
    //-9 omdat we een vloeiend overgang willen creeren en dus een extra stuk weg moeten kunnen generen in de wereld
    if(this->getLocation().second > 3 || this->getLocation().second < -9){
        crashed = true;
    }
}

/**
 * @brief functie die controleert of de weg nog op de weg ligt, doet natuurlijk niets.
 */
void RF::Road::checkIfOnRoad()
{
}

/**
 * @brief functie die controleert of de Road collision heeft met een ander object, doet natuurlijk niets.
 *
 * @param other het object waarmee collision wordt gecontroleerd.
 */
void RF::Road::checkIfCollided(const std::shared_ptr<Entity > &other)
{
}