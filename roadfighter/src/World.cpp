
#include "roadfighter/include/World.h"

RF::World::World() = default;

RF::World::~World() = default;

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
    std::shared_ptr<Player > player;

    for(auto &object:livingObjects)
    {
        object->update();
        if(std::dynamic_pointer_cast<Player>(object)){
            player = std::dynamic_pointer_cast<Player>(object);
        }
    }

    this->correctPosition(player->getMovement());

}

void RF::World::checkIfOnRoad(const double &sideline)
{
    for(auto &object:livingObjects){
        object->checkIfOnRoad(sideline);
    }
}

void RF::World::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
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

void RF::World::correctPosition(const RF::PlaneLocation &correctionVector)
{
    for(auto &object:livingObjects)
    {
        object->correctPosition(correctionVector);
    }
}

void RF::World::setMovement(RF::movementVector &addedVelocity)
{
    for(auto &object: livingObjects){
        if(std::dynamic_pointer_cast<Player >(object)){
            object->setMovement(addedVelocity);
            break;
        }
    }
}

void RF::World::draw() {
    for(auto &object: livingObjects){
        object->draw();
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

void RF::World::attackAction(std::shared_ptr<RF::Entity> world)
{
    throw RoadfighterError("You can't make the world attack, not all objects can attack.");
}


