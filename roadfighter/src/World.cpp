
#include "roadfighter/include/World.h"

namespace RF {
    double endOfRoad;
}

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
    std::shared_ptr<Player > player = nullptr;

    std::vector<std::vector<std::shared_ptr<Entity > >::iterator > dyingObjects;

    for(auto objectptr = livingObjects.begin(); objectptr != livingObjects.end(); objectptr++)
    {

        //we controleren of het object is gecrasht
        (*objectptr)->checkIfInWorld();
        (*objectptr)->checkIfOnRoad();

        for(auto &otherObject: livingObjects){
            if((!std::dynamic_pointer_cast<RF::Road >(otherObject)) && (otherObject) != (*objectptr)) {
                (*objectptr)->checkIfCollided(otherObject);
            }
        }

        if((*objectptr)->hasCrashed()){
            dyingObjects.emplace_back(objectptr);
        }

        //we updaten het object
        (*objectptr)->update();

        //we kijken of het object de speler is
        if(std::dynamic_pointer_cast<Player>(*objectptr)){
            player = std::dynamic_pointer_cast<Player>(*objectptr);
        }
    }

    if(player) {
        this->correctPosition(player->getMovement());
    }

    for(auto &object:dyingObjects){
        livingObjects.erase(object);
    }

}

void RF::World::checkIfOnRoad()
{
    for(auto &object:livingObjects){
        object->checkIfOnRoad();
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

void RF::World::accelerate(RF::movementVector &acceleration)
{
    for(auto &object: livingObjects){
        if(std::dynamic_pointer_cast<Player >(object)){
            object->accelerate(acceleration);
            break;
        }
    }
}

void RF::World::draw() {
    for(auto &object: livingObjects){
        object->draw();
    }
}

void RF::World::checkIfInWorld() {
    throw RoadfighterError("The world can't be outside the world.");
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


