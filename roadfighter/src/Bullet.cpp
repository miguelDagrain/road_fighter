
#include "roadfighter/include/Player.h"

#include "roadfighter/include/Bullet.h"


RF::Bullet::Bullet() = default;

RF::Bullet::~Bullet() = default;


RF::Bullet::Bullet(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) : Entity(entityLocation, entitySize, movement) {

}

void RF::Bullet::checkIfCollided(const std::shared_ptr<RF::Entity> &other) {
    //eerst controleren we of we ons niet rechts van de andere entiteit begeven, zoniet ga verder...
    if(this->getLocation().first <= (other->getLocation().first+other->getSize().first))
    {
        //dan controleren we of we ons niet links van de andere entiteit begeven, zoniet ga verder...
        if((this->getLocation().first+this->getSize().first) >= other->getLocation().first)
        {
            //vervolgens controleren we of we ons niet onder de andere entiteit begeven, zoniet ga verder...
            if((this->getLocation().second <= (other->getLocation().second+other->getSize().second)))
            {
                //tot slot controleren we of we ons niet boven de andere entiteit begeven, zoniet dan heb je collision
                if((this->getLocation().second+this->getSize().second) >= other->getLocation().second){
                    //we kunnen natuurlijk niet crashen tegen de speler
                    if (std::dynamic_pointer_cast<RF::Player >(other)){

                    }else{
                        crashed = true;
                    }

                }
            }

        }
    }
}
