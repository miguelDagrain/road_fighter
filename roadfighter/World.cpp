//
// Created by miguel on 02.12.18.
//

#include "World.h"

void RF::World::addObject(std::shared_ptr<RF::Entity> newbornObject)
{
    livingObjects.emplace_back(newbornObject);
}

void RF::World::removeObject(std::shared_ptr<RF::Entity> deadObject)
{
    auto positionObject = std::find(livingObjects.begin(), livingObjects.end(), deadObject);
    livingObjects.erase(positionObject);
}

void RF::World::update()
{
    for(auto &object:livingObjects)
    {
        object->update();
    }
}

void RF::World::checkIfOnRoad(const double &sideline)
{
    for(auto &object:livingObjects){
        object->checkIfOnRoad(sideline);
    }
}

void RF::World::checkIfCollided(std::shared_ptr<RF::Entity> other)
{
    for(auto &object:livingObjects){

        object->checkIfCollided(other);

    }
}

void RF::World::checkOnCollision()
{
    for(auto &object:livingObjects){
        checkIfCollided(object);
    }
}

void RF::World::correctPosition(RF::PlaneLocation &correctionVector)
{
    for(auto &object:livingObjects)
    {
        object->correctPosition(correctionVector);
    }
}

bool RF::World::hasCrashed() const {
    throw RoadfighterError("The world can't crash.");
}

const RF::location &RF::World::getLocation() const
{
    throw RoadfighterError("You can't ask the location of the world, it has none.");
}

const RF::size &RF::World::getSize() const
{
    throw RoadfighterError("You can't ask the size of the world, it has none.");
}

const RF::movementVector &RF::World::getMovement() const
{
    throw RoadfighterError("You can't ask the movement of the world, it has none.");
}

void RF::World::setMovement(RF::movementVector &newVelocity)
{
    throw RoadfighterError("You can't set the movement of the world, it has none.");
}

std::vector<std::shared_ptr<RF::Entity>, std::allocator<std::shared_ptr<RF::Entity>>>::const_iterator
RF::World::begin() const
{
    return livingObjects.begin();
}

std::vector<std::shared_ptr<RF::Entity>, std::allocator<std::shared_ptr<RF::Entity>>>::const_iterator
RF::World::end() const
{
    return livingObjects.end();
}
