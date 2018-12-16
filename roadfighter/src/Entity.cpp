
#include "roadfighter/include/Entity.h"

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

bool RF::Entity::hasCrashed() const
{
    return crashed;
}

void RF::Entity::setMovement(RF::movementVector &newVelocity)
{
    movement = newVelocity;
}

void RF::Entity::attackAction(std::shared_ptr<Entity > world)
{
}

void RF::Entity::checkIfOnRoad(const double& sideLine)
{

    if(entityLocation.first < -(sideLine) || entityLocation.first > (sideLine)){
        crashed = true;
    }
}

void RF::Entity::checkIfCollided(const std::shared_ptr<RF::Entity> other)
{
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
                    crashed = true;
                }
            }

        }
    }
}

void RF::Entity::checkOnCollision()
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
