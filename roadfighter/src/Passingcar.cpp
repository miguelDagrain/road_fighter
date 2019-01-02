
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/Passingcar.h"

/**
 * @brief basis constructor voor een Passingcar.
 */
RF::Passingcar::Passingcar() = default;

/**
 * @brief destructor voor een Passingcar.
 */
RF::Passingcar::~Passingcar() = default;

/**
 * @brief constructor voor een Passingcar met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van de Passingcar.
 * @param entitySize grootte van de Passingcar.
 * @param movement beweging van de Passingcar.
 */
RF::Passingcar::Passingcar(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
}

/**
 * @brief functie die controleert of deze Passingcar collision heeft met een andere entiteit.
 *
 * @param other entiteit waarmee collision mee wordt gecontroleerd.
 */
void RF::Passingcar::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
    if(!std::dynamic_pointer_cast<RF::Road>(other)) {

        //eerst controleren we of we ons niet onder de andere entiteit begeven, zoniet ga verder...
        if ((this->getLocation().second <= (other->getLocation().second + other->getSize().second))) {
            //dan controleren we of we ons niet boven de andere entiteit begeven, zoniet ga verder...
            if ((this->getLocation().second + this->getSize().second) >= other->getLocation().second) {
                //vervolgens controleren we of we ons niet rechts van de andere entiteit begeven, zoniet ga verder...
                if (this->getLocation().first <= (other->getLocation().first + other->getSize().first)) {
                    //tot slot controleren we of we ons niet links van de andere entiteit begeven, zoniet dan heb je collision
                    if ((this->getLocation().first + this->getSize().first) >= other->getLocation().first) {
                        crashed = true;

                        if (std::dynamic_pointer_cast<RF::Bullet>(other)) {
                            observer->notifyShotEntity();
                        }
                    }
                }

            }
        }
    }
}