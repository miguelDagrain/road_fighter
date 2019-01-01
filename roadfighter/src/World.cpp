
#include "roadfighter/include/World.h"

namespace RF {
    double endOfRoad;
}

RF::World::World() = default;

RF::World::~World() = default;

void RF::World::addObject(std::shared_ptr<RF::Entity> newbornObject)
{
    if(observer) {
        std::shared_ptr<RF::ObserverWorld> copy(observer);
        newbornObject->setObserver(std::move(copy));
    }

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

    //we updaten het object
    for(auto &object: livingObjects){
        object->update();

        //we kijken of het object de speler is
        if(std::dynamic_pointer_cast<Player>(object)){
            player = std::dynamic_pointer_cast<Player>(object);
        }
    }

    //corigeer het beeld
    if(player) {
        this->correctPosition(player->getMovement());
    }

    //controleer of objecten crashen
    for (auto &livingObject : livingObjects) {
        //we controleren of het object is gecrasht
        livingObject->checkIfInWorld();
        livingObject->checkIfOnRoad();

        for (auto &otherObject: livingObjects) {
            if (otherObject != livingObject) {
                livingObject->checkIfCollided(otherObject);
            }
        }
    }

    //verwijder onnodige objecten niet meteen omdat we collision tussen verschillende objecten bij beide objecten moeten merken
    for(auto objectptr = livingObjects.begin(); objectptr != livingObjects.end(); ++objectptr) {
        if((*objectptr)->hasCrashed()){
            if(std::dynamic_pointer_cast<RF::Road>(*objectptr)){
                observer->notifyEndWorld((*objectptr)->getLocation());
            }

            if(std::dynamic_pointer_cast<RF::Player>(*objectptr)){
                observer->notifyExistPlayer();
            }

            livingObjects.erase(objectptr);

            --objectptr;
        }

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

void RF::World::correctPosition(RF::PlaneLocation correctionVector)
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

std::shared_ptr<RF::Entity> RF::World::attackAction(RF::Entity &world)
{
    for(auto &object:livingObjects){
        if(std::dynamic_pointer_cast<Player >(object)){
            return object->attackAction(world);
        }
    }
    return nullptr;
}

void RF::World::draw() {
    for(auto &object: livingObjects){
        if(std::dynamic_pointer_cast<RF::Road>(object)){

            object->draw();

        }
    }
    for(auto &object: livingObjects){
        if(!std::dynamic_pointer_cast<RF::Road>(object)) {
            if(object->getLocation().second > -4 && object->getLocation().second < 3) {
                object->draw();
            }
        }
    }
}


void RF::World::setObserver(std::shared_ptr<RF::ObserverWorld> &&observerPtr)
{
    observer = observerPtr;
    for(auto &object:livingObjects){
        std::shared_ptr<RF::ObserverWorld > copy(observer);
        object->setObserver(std::move(copy));
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



