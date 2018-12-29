
#include "roadfighter/include/Player.h"

RF::Player::Player() = default;

RF::Player::~Player() = default;

RF::Player::Player(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
Entity(entityLocation, entitySize, movement)
{

}


void RF::Player::attackAction(std::shared_ptr<Entity > world) {
//    Factory factory;
//    location tempLoc = this->getLocation();
//    movementVector tempMove =  (this->getMovement()*1.5);
//    world->addObject(factory.createBullet(tempLoc, tempMove));
}
