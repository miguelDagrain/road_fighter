

#include "roadfighter/include/Player.h"
#include "roadfighter/include/EntityFactory.h"

RF::Player::Player(RF::location &entityLocation, RF::size &entitySize) : Entity(entityLocation, entitySize) {

}

void RF::Player::attackAction(std::shared_ptr<Entity > world) {
    RF::Factory::BulletFactory factory;
    location temp = this->getLocation();
    world->addObject(factory.createEntity(temp));
}
