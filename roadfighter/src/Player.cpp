
#include <roadfighter/include/Player.h>

#include "roadfighter/include/Racer.h"
#include "roadfighter/include/Passingcar.h"
#include "roadfighter/include/Fuelcar.h"
#include "roadfighter/include/Player.h"

RF::Player::Player() = default;

RF::Player::~Player() = default;

RF::Player::Player(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}


void RF::Player::update() {

    entityLocation += movement;

    if(specialActionDuration == 0) {
        rotation = 0;

        if (movement.second > 0) {
            movement.second = 0;
        }

        movement.first = 0;
    }else{

        --specialActionDuration;
    }

}

void RF::Player::correctPosition(RF::PlaneLocation correctionVector)
{
    entityLocation.second -= correctionVector.second;

    if(movement.second < 0) {
        movement.second += 0.001;
    }
}

void RF::Player::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
    if(specialActionDuration == 0){
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

                        //we controleren welk soort wagen we tegen aangebotst zijn
                        if(std::dynamic_pointer_cast<RF::Passingcar>(other)){
                            if(entityLocation.first < other->getLocation().first){
                                movement.first = -0.02;
                                rotation = 40;
                            }else{
                                movement.first = 0.02;
                                rotation = -40;
                            }


                            specialActionDuration = 50;
                        } else if(std::dynamic_pointer_cast<RF::Fuelcar>(other)){

                        } else if(std::dynamic_pointer_cast<RF::Racer>(other)){
                            specialActionDuration = 50;
                        }

                    }

                }

            }
        }
    }
}


