
#include "Entity.h"

RF::Entity::Entity(location & entityLocation, size & entitySize) : entityLocation(entityLocation), entitySize(entitySize)
{
    movementVector stationary(0, 0);
    movement = stationary;
}

RF::Entity::Entity(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
entityLocation(entityLocation),
entitySize(entitySize),
movement(movement)
{
}

void RF::Entity::addObject(std::shared_ptr<RF::Entity> newbornObject)
{
    throw RoadfighterError("You can't add an object to this kind of Entity.");
}

void RF::Entity::removeObject(std::shared_ptr<RF::Entity> deadObject)
{
    throw RoadfighterError("You can't remove an object from this kind of Entity.");
}

const RF::location &RF::Entity::getLocation() const
{
    return entityLocation;
}

const RF::size &RF::Entity::getSize() const
{
    return entitySize;
}

const RF::movementVector &RF::Entity::getMovement() const
{
    return movement;
}

void RF::Entity::setMovement(RF::movementVector &newVelocity)
{
    movement = newVelocity;
}

void RF::Entity::attackAction(std::shared_ptr<Entity > world)
{
}

void RF::Entity::update()
{
    entityLocation += movement;
}

void RF::Entity::correctPosition(RF::PlaneLocation &correctionVector)
{
    entityLocation -= correctionVector;
}
