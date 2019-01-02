
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Racer.h"

/**
 * @brief basis constructor van een Racer.
 */
RF::Racer::Racer() = default;

/**
 * @brief destructor van een Racer.
 */
RF::Racer::~Racer() = default;

/**
 * @brief constructor van een Racer met locatie, grootte en beweging
 *
 * @param entityLocation locatie van de Racer.
 * @param entitySize grootte van de Racer.
 * @param movement beweging van de Racer.
 */
RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
    specialActionDuration = 400;
}

/**
 * @brief functie die een update doet van de Racer.
 */
void RF::Racer::update() {

    if(specialActionDuration == 0) {

        entityLocation += movement;

    }else{

        entityLocation += movement*2;

        --specialActionDuration;
    }

}

/**
 * @brief functie die controleert of de Racer collision heeft met een andere entiteit.
 *
 * @param other de andere entiteit waarmee collision wordt gecontroleerd.
 */
void RF::Racer::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
    if(std::dynamic_pointer_cast<RF::Bullet >(other)) {
        //eerst controleren we of we ons niet onder de andere entiteit begeven, zoniet ga verder...
        if((this->getLocation().second <= (other->getLocation().second+other->getSize().second)))
        {
            //dan controleren we of we ons niet boven de andere entiteit begeven, zoniet ga verder...
            if((this->getLocation().second+this->getSize().second) >= other->getLocation().second)
            {
                //vervolgens controleren we of we ons niet rechts van de andere entiteit begeven, zoniet ga verder...
                if(this->getLocation().first <= (other->getLocation().first+other->getSize().first))
                {
                    //tot slot controleren we of we ons niet links van de andere entiteit begeven, zoniet dan heb je collision
                    if((this->getLocation().first+this->getSize().first) >= other->getLocation().first) {
                        movement.second += 0.002;

                    }
                }

            }
        }
    }
}

/**
 * @brief Controleer of de racers nog in het spel zitten (ze kunnen niet verwijdert worden).
 */
void RF::Racer::checkIfInWorld()
{
}