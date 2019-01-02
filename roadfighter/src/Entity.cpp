
#include "roadfighter/include/World.h"
#include "roadfighter/include/Bullet.h"

#include "roadfighter/include/Entity.h"

/**
 * @brief basis constructor van een entiteit.
 */
RF::Entity::Entity(): crashed(false), rotation(0), specialActionDuration(0)
{
    RF::location loc(0, 0);
    entityLocation = loc;

    RF::size size1(0, 0);
    entitySize = size1;

    movementVector stationary(0, 0);
    movement = stationary;
};

/**
 * @brief constructor van een object met locatie, grootte en beweging
 *
 * @param entityLocation locatie van het object
 * @param entitySize grootte van het object
 * @param movement beweging van het object
 */
RF::Entity::Entity(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
entityLocation(entityLocation),
entitySize(entitySize),
movement(movement),
crashed(false),
rotation(0),
specialActionDuration(0)
{
}

/**
 * @brief basis destructor van een object
 */
RF::Entity::~Entity() = default;

/**
 * @brief functie die een object toevoegt aan deze entiteit, enkel nodig voor de  composition afgeleide.
 *
 * @param newbornObject het object dat wordt toegevoegd.
 */
void RF::Entity::addObject(std::shared_ptr<RF::Entity> newbornObject)
{
    throw RoadfighterError("You can't add an object to this kind of Entity.");
}

/**
 * @brief functie die een object verwijdert uit deze entiteit, enkel nodig voor de composition afgeleide.
 *
 * @param deadObject het object dat wordt verwijderd.
 */
void RF::Entity::removeObject(std::shared_ptr<RF::Entity> deadObject)
{
    throw RoadfighterError("You can't remove an object from this kind of Entity.");
}

/**
 * @brief functie die de observer zet voor deze entiteit.
 *
 * @param observerPtr de ptr naar de observer die wordt gebruikt om de entiteit te observeren.
 */
void RF::Entity::setObserver(std::shared_ptr<RF::ObserverWorld> &&observerPtr)
{
    observer = observerPtr;
}

/**
 * @brief functie die de observer van deze entiteit teruggeeft.
 *
 * @return de observer van deze entiteit.
 */
const std::shared_ptr<RF::ObserverWorld> RF::Entity::getObserver() const
{
    return observer;
}

/**
 * @brief functie die de locatie van deze entiteit teruggeeft.
 *
 * @return locatie van deze entiteit
 */
const RF::location &RF::Entity::getLocation() const
{
    return entityLocation;
}

/**
 * @brief functie die de grootte van deze entiteit teruggeeft.
 *
 * @return grootte van deze entiteit.
 */
const RF::size &RF::Entity::getSize() const
{
    return entitySize;
}

/**
 * @brief functie die de beweging van deze entiteit teruggeeft.
 *
 * @return de beweging van deze entiteit.
 */
const RF::movementVector &RF::Entity::getMovement() const
{
    return movement;
}

/**
 * @brief functie die weergeeft of deze entiteit is gecrashd.
 *
 * @return of de entiteit al dan niet gecrashd is.
 */
bool RF::Entity::hasCrashed() const
{
    return crashed;
}

/**
 * @brief functie die deze entiteit laat acceleren.
 *
 * @param acceleration de acceleratie waarmee deze entiteit versneld.
 */
void RF::Entity::accelerate(RF::movementVector &acceleration)
{
    if(specialActionDuration == 0) {

        movement.first += acceleration.first;

        if (movement.second > -0.06) {
            movement.second += acceleration.second;
        }

    }
}

/**
 * @brief functie die een entiteit teruggeeft die de aanval van deze entiteit voorstelt
 *
 * @param world de entiteit waarin de aanval wordt uitgevoerd.
 * @return nullptr omdat dit de basisklasse is.
 */
std::shared_ptr<RF::Entity > RF::Entity::attackAction()
{
    return nullptr;
}

/**
 * @brief functie die controleert of de entiteit nog bestaat (we willen niet alle entiteiten voortdurend bijhouden).
 */
void RF::Entity::checkIfInWorld()
{
    if(this->getLocation().second > 3.5){
        this->crashed = true;
    }
}

/**
 * @brief functie die controleert of de entiteit nog op de weg is, gebruikmakende van een namespace variable.
 */
void RF::Entity::checkIfOnRoad()
{

    if(entityLocation.first < -(RF::endOfRoad) || entityLocation.first > (RF::endOfRoad-0.4)){
        crashed = true;
    }
}

/**
 * @brief functie die controleert of de entiteit collision heeft men een andere entiteit.
 *
 * @param other de entiteit waarmee op collision wordt gecontroleerd.
 */
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

/**
 * @brief functie die de entiteit update.
 */
void RF::Entity::update()
{
    entityLocation += movement;

}

/**
 * @brief functie die de locatie aanpast met voor correcte presentatie te krijgen (rond de speler).
 *
 * @param correctionVector de vector waarmee we de positie corrigeren.
 */
void RF::Entity::correctPosition(RF::PlaneLocation correctionVector)
{
    entityLocation.second -= correctionVector.second;
}

/**
 * @brief functie op een entiteit te tekenen (logischerwijs kunnen we hier nog niets doen).
 */
void RF::Entity::draw()
{
}

