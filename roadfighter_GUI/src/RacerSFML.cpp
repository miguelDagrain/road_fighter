#include "roadfighter_GUI/include/RacerSFML.h"

/**
 * @brief basis constructor voor een RacerSFML.
 */
RF_GUI::RacerSFML::RacerSFML() = default;

/**
 * @brief constructor voor RacerSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van RacerSFML.
 * @param entitySize grootte van RacerSFML.
 * @param movement beweging van RacerSFML.
 */
RF_GUI::RacerSFML::RacerSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
RF::Racer(entityLocation, entitySize, movement)
{
}

/**
 * @brief destructor van RacerSFML.
 */
RF_GUI::RacerSFML::~RacerSFML() = default;

/**
 * @brief functie die een RacerSFML tekent.
 */
void RF_GUI::RacerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/racing_car.png");

    sprite.setTexture(texture);

    sf::Vector2u sizeTexture = texture.getSize();

    auto scaleX = static_cast<float >(this->getSize().first/sizeTexture.x);
    auto scaleY = static_cast<float >(this->getSize().second/sizeTexture.y);

    sprite.scale(scaleX, scaleY);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    sprite.setRotation(this->rotation);

    auto transform = Transformation::getInstance();

    (*transform)(sprite);
}
