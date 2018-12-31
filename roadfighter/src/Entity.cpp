
#include "roadfighter/include/World.h"
#include "roadfighter/include/Bullet.h"

#include "roadfighter/include/Entity.h"


RF::Entity::Entity(): crashed(false), rotation(0), specialActionDuration(0)
{
    RF::location loc(0, 0);
    entityLocation = loc;

    RF::size size1(0, 0);
    entitySize = size1;

    movementVector stationary(0, 0);
    movement = stationary;
};

RF::Entity::Entity(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
entityLocation(entityLocation),
entitySize(entitySize),
movement(movement),
crashed(false),
rotation(0),
specialActionDuration(0)
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

void RF::Entity::setObserver(std::shared_ptr<RF::ObserverWorld> &&observerPtr)
{
    observer = observerPtr;
}

const std::shared_ptr<RF::ObserverWorld> RF::Entity::getObserver() const
{
    return observer;
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
    if(specialActionDuration == 0) {

        movement.first += acceleration.first;

        if (movement.second > -0.06) {
            movement.second += acceleration.second;
        }

    }
}

void RF::Entity::attackAction(Entity &world)
{
}

void RF::Entity::checkIfInWorld()
{
    if(this->getLocation().second > 3.5){
        this->crashed = true;
    }
}

void RF::Entity::checkIfOnRoad()
{

    if(entityLocation.first < -(RF::endOfRoad) || entityLocation.first > (RF::endOfRoad-0.4)){
        crashed = true;
    }
}

void RF::Entity::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
    if(!std::dynamic_pointer_cast<RF::Road>(other)) {

        //eerst controleren we of we ons niet onder de andere entiteit begeven, zoniet ga verder...
        if ((this->getLocation().second <= (other->getLocation().second + other->getSize().second))) {
            //dan controleren we of we ons niet boven de andere entiteit begeven, zoniet ga verder...
            if ((this->getLocation().second + this->getSize().second) >= other->getLocation().second) {
                //vervolgens controleren we of we ons niet rechts van de andere entiteit begeven, zoniet ga verder...
                if (this->getLocation().first <= (other->getLocation().first + other->getSize().first)) {
                    //tot slot controleren we of we ons niet links van de andere entiteit begeven, zoniet dan heb je collision
                    if ((this->getLocation().first + this->getSize().first) >= other->getLocation().first) {
                        crashed = true;

                    }
                }

            }
        }
    }
}


void RF::Entity::update()
{
    entityLocation += movement;

}

void RF::Entity::correctPosition(RF::PlaneLocation correctionVector)
{
    entityLocation.second -= correctionVector.second;
}

void RF::Entity::draw()
{
}

