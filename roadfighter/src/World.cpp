#include "roadfighter/include/World.h"

namespace RF {
    double endOfRoad;
}

/**
 * @brief basis constructor voor een World.
 */
RF::World::World() = default;

/**
 * @brief destructor voor World.
 */
RF::World::~World() = default;

/**
 * @brief functie die een entiteit toevoegd aan de World.
 *
 * @param newbornObject de entiteit dat wordt toegevoegd.
 */
void RF::World::addObject(std::shared_ptr<RF::Entity> newbornObject)
{
    if(observer) {
        std::shared_ptr<RF::ObserverWorld> copy(observer);
        newbornObject->setObserver(std::move(copy));
    }

    livingObjects.emplace_back(newbornObject);
}

/**
 * @brief functie die een entiteit verwijderd uit de World.
 *
 * @param deadObject de entiteit die wordt verwijderd.
 */
void RF::World::removeObject(std::shared_ptr<RF::Entity> deadObject)
{
    auto positionObject = std::find(livingObjects.begin(), livingObjects.end(), deadObject);
    livingObjects.erase(positionObject);
}

/**
 * @brief functie die een update uitvoerd op de World en al zijn objecten.
 */
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

/**
 * @brief functie die controleert of de entiteiten van de World nog op de weg zitten.
 */
void RF::World::checkIfOnRoad()
{
    for(auto &object:livingObjects){
        object->checkIfOnRoad();
    }
}

/**
 * @brief functie die contreleert of de entiteiten collision hebben met een andere entiteit.
 *
 * @param other de entiteit waarmee de collision wordt gecontroleerd.
 */
void RF::World::checkIfCollided(const std::shared_ptr<RF::Entity> &other)
{
    for(auto &object:livingObjects){

        object->checkIfCollided(other);

    }
}

/**
 * @brief functie die positie van de entiteiten corrigeert.
 *
 * @param correctionVector de vector waarmee we de entiteiten corrigeren.
 */
void RF::World::correctPosition(RF::PlaneLocation correctionVector)
{
    for(auto &object:livingObjects)
    {
        object->correctPosition(correctionVector);
    }
}

/**
 * @brief functie die de correcte entiteiten versneld.
 *
 * @param acceleration de vector die de versnelling aangeeft.
 */
void RF::World::accelerate(RF::movementVector &acceleration)
{
    for(auto &object: livingObjects){
        if(std::dynamic_pointer_cast<Player >(object)){
            object->accelerate(acceleration);
            break;
        }
    }
}

/**
 * @brief functie die de objecten die kunnen een aanval laten uitvoeren.
 *
 * @return entiteit die de aanval voorstelt
 */
std::shared_ptr<RF::Entity> RF::World::attackAction()
{
    for(auto &object:livingObjects){
        if(std::dynamic_pointer_cast<Player >(object)){
            return object->attackAction();
        }
    }
    return nullptr;
}

/**
 * @brief de entiteiten in de World worden getekend.
 */
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

/**
 * @brief functie die de observer zet voor de World en zijn entiteiten.
 *
 * @param observerPtr de ptr naar de observer die zal gebruikt worden.
 */
void RF::World::setObserver(std::shared_ptr<RF::ObserverWorld> &&observerPtr)
{
    observer = observerPtr;
    for(auto &object:livingObjects){
        std::shared_ptr<RF::ObserverWorld > copy(observer);
        object->setObserver(std::move(copy));
    }
}

/**
 * @brief functie om te controleren of de World in de wereld ligt, dit kan natuurlijk niet voor de World.
 */
void RF::World::checkIfInWorld() {
    throw RoadfighterError("The world can't be outside the world.");
}

/**
 * @brief functie die controleert of de World is gecrasht, dit kan natuurlijk niet op de World zelf worden toegepast.
 *
 * @return niet van toepassing er wordt hier een error geworpen.
 */
bool RF::World::hasCrashed() const {
    throw RoadfighterError("The world can't crash.");
}

/**
 * @brief functie die de locatie weergeeft van de World, kan niet voor de World.
 *
 * @return niet van toepassing er wordt hier een error geworpen.
 */
const RF::location &RF::World::getLocation() const
{
    throw RoadfighterError("You can't ask the location of the world, it has none.");
}

/**
 * @brief functie die de grootte weergeeft van de World, kan niet voor de World.
 *
 * @return niet van toepassing er wordt hier een error geworpen.
 */
const RF::size &RF::World::getSize() const
{
    throw RoadfighterError("You can't ask the size of the world, it has none.");
}

/**
 * @brief functie die de beweging weergeeft van de World, kan niet voor de World.
 *
 * @return niet van toepassing er wordt hier een error geworpen.
 */
const RF::movementVector &RF::World::getMovement() const
{
    throw RoadfighterError("You can't ask the movement of the world, it has none.");
}



