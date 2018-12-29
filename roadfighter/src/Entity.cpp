
#include <roadfighter/include/Entity.h>

#include "roadfighter/include/World.h"
#include "roadfighter/include/Entity.h"


RF::Entity::Entity(): crashed(false)
{
    RF::location loc(0, 0);
    entityLocation = loc;

    RF::size size1(0, 0);
    entitySize = size1;

    movementVector stationary(0, 0);
    movement = stationary;
};

RF::Entity::Entity(location & entityLocation, size & entitySize) : entityLocation(entityLocation), entitySize(entitySize), crashed(false)
{
    movementVector stationary(0, 0);
    movement = stationary;
}

RF::Entity::Entity(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
entityLocation(entityLocation),
entitySize(entitySize),
movement(movement),
crashed(false)
{
}

RF::Entity::~Entity() = default;

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

void RF::Entity::accelerate(RF::movementVector &acceleration)
{
    movement.first += acceleration.first;

    if(movement.second > -0.08) {
        movement.second += acceleration.second;
    }
}

void RF::Entity::attackAction(std::shared_ptr<Entity > world)
{
}

void RF::Entity::checkIfInWorld()
{
    if(this->getLocation().first > 4 || this->getLocation().first < -4 || this->getLocation().second > 3 || this->getLocation().second < -3){
        this->crashed = true;
    }
}

void RF::Entity::checkIfOnRoad()
{

    if(entityLocation.first < -(RF::endOfRoad) || entityLocation.first > (RF::endOfRoad)){
        crashed = true;
    }
}

void RF::Entity::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
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
    if(movement.second > 0) {
        movement.second = 0;
    }
    entityLocation += movement;

    movement.first = 0;

}

void RF::Entity::correctPosition(RF::PlaneLocation correctionVector)
{
    entityLocation.second -= correctionVector.second;
}

void RF::Entity::draw()
{
}

