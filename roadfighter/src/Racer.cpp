
#include <roadfighter/include/Racer.h>
#include <roadfighter/include/Bullet.h>

#include "roadfighter/include/Racer.h"

RF::Racer::Racer() = default;

RF::Racer::~Racer() = default;

RF::Racer::Racer(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
    specialActionDuration = 400;
}


void RF::Racer::update() {

    if(specialActionDuration == 0) {

        entityLocation += movement;

    }else{

        entityLocation += movement*2;

        --specialActionDuration;
    }

}

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


void RF::Racer::checkIfInWorld()
{
    //racers blijven in het spel
}