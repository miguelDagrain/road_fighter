
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/Racer.h"
#include "roadfighter/include/Passingcar.h"
#include "roadfighter/include/Fuelcar.h"
#include "roadfighter/include/Finish.h"
#include "roadfighter/include/Player.h"

/**
 * @brief basis constructor van een Player.
 */
RF::Player::Player() = default;

/**
 * @brief destructor van een Player
 */
RF::Player::~Player() = default;

/**
 * @brief constructor van een Player met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van de Player.
 * @param entitySize grootte van de Player.
 * @param movement beweging van de Player.
 */
RF::Player::Player(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{
    specialActionDuration = 100;
}

/**
 * @brief functie die weergeeft of de speler is gecrasht.
 *
 * @return of de Player al dan niet is gecrasht.
 */
bool RF::Player::hasCrashed() const
{
    if(crashed){
        observer->notifyCrashed();
    }

    return crashed;
}

/**
 * @brief functie die de Player update.
 */
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

/**
 * @brief functie die de locatie van de Player corrigeert (voor representatie).
 *
 * @param correctionVector de vector waarmee we de positie corrigeren
 */
void RF::Player::correctPosition(RF::PlaneLocation correctionVector)
{
    entityLocation.second -= correctionVector.second;

    if(movement.second < 0) {
        movement.second += 0.001;
    }
}

/**
 * @brief functie die controleert of de Player collision heeft met een andere entiteit.
 *
 * @param other de andere entiteit.
 */
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

/**
 * @brief functie die een de aanval van de Player voorstelt.
 *
 * @return shared ptr naar de entiteit die aanval voorstelt.
 */
std::shared_ptr<RF::Entity > RF::Player::attackAction()
{
    RF::location standardLoc(this->getLocation());
    RF::size standardBullet(0.3, 0.3);
    RF::movementVector standardMovement(this->getMovement()*1.5);

    return std::make_shared<RF::Bullet >(standardLoc, standardBullet, standardMovement);
}

