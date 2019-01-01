
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/Racer.h"
#include "roadfighter/include/Passingcar.h"
#include "roadfighter/include/Fuelcar.h"
#include "roadfighter/include/Finish.h"
#include "roadfighter/include/Player.h"

RF::Player::Player() = default;

RF::Player::~Player() = default;

RF::Player::Player(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
    specialActionDuration = 100;
}

bool RF::Player::hasCrashed() const
{
    if(crashed){
        observer->notifyCrashed();
    }

    return crashed;
}

void RF::Player::update()
{
    observer->notifyTimePassed();

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


    if(specialActionDuration == 0 && !(std::dynamic_pointer_cast<RF::Bullet >(other))){
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
                    if((this->getLocation().first+this->getSize().first) >= other->getLocation().first){

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
                        } else if(std::dynamic_pointer_cast<RF::Finish>(other)){
                            observer->notifyFinished();
                        }

                    }

                }

            }
        }
    }

}


std::shared_ptr<RF::Entity > RF::Player::attackAction(RF::Entity &world)
{
    RF::location standardLoc(this->getLocation());
    RF::size standardBullet(0.3, 0.3);
    RF::movementVector standardMovement(this->getMovement()*1.5);

    return std::make_shared<RF::Bullet >(standardLoc, standardBullet, standardMovement);
}

