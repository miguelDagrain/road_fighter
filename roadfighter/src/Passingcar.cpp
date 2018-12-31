
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/Passingcar.h"

RF::Passingcar::Passingcar() = default;

RF::Passingcar::~Passingcar() = default;


RF::Passingcar::Passingcar(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}

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