
#include "roadfighter/include/Player.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/Bullet.h"

/**
 * @brief basis constructor voor een bullet.
 */
RF::Bullet::Bullet() = default;

/**
 * @brief basis destructor voor een bullet
 */
RF::Bullet::~Bullet() = default;

/**
 * @brief constructor van bullet met locatie, grootte en beweging
 *
 * @param entityLocation locatie van het object
 * @param entitySize grootte van het object
 * @param movement beweging van het object
 */
RF::Bullet::Bullet(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) : Entity(entityLocation, entitySize, movement)
{
}

/**
 * @brief functie die controlleert of er collision is tussen deze kogel en een ander object.
 *
 * @param other het andere object waarvan we controleren of er collision is.
 */
void RF::Bullet::checkIfCollided(const std::shared_ptr<RF::Entity> &other) {

    if(!std::dynamic_pointer_cast<RF::Road>(other)){

        //eerst controleren we of we ons niet onder de andere entiteit begeven, zoniet ga verder...
        if ((this->getLocation().second <= (other->getLocation().second + other->getSize().second))) {
            //dan controleren we of we ons niet boven de andere entiteit begeven, zoniet ga verder...
            if ((this->getLocation().second + this->getSize().second) >= other->getLocation().second) {
                //vervolgens controleren we of we ons niet rechts van de andere entiteit begeven, zoniet ga verder...
                if (this->getLocation().first <= (other->getLocation().first + other->getSize().first)) {
                    //tot slot controleren we of we ons niet links van de andere entiteit begeven, zoniet dan heb je collision
                    if ((this->getLocation().first + this->getSize().first) >= other->getLocation().first) {
                        //we kunnen natuurlijk niet crashen tegen de speler
                        if (!(std::dynamic_pointer_cast<RF::Player>(other))) {
                            crashed = true;
                        }

                    }
                }

            }
        }
    }
}
