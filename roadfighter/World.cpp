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
    for(auto& object:livingObjects)
    {
        object->update();
    }
}


void RF::World::correctPosition(RF::PlaneLocation &correctionVector)
{
    for(auto& object:livingObjects)
    {
        object->correctPosition(correctionVector);
    }
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