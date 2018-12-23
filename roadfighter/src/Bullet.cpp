
#include "roadfighter/include/Bullet.h"


RF::Bullet::Bullet() = default;

RF::Bullet::~Bullet() = default;


RF::Bullet::Bullet(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) : Entity(entityLocation, entitySize, movement) {

}
