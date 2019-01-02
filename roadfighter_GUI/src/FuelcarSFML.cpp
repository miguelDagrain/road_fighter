
#include "roadfighter_GUI/include/FuelcarSFML.h"

/**
 * @brief basis constructor voor een FuelcarSFML.
 */
RF_GUI::FuelcarSFML::FuelcarSFML() = default;

/**
 * @brief constructor voor FuelcarSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van FuelcarSFML.
 * @param entitySize grootte van FuelcarSFML.
 * @param movement beweging van FuelcarSFML.
 */
RF_GUI::FuelcarSFML::FuelcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
RF::Fuelcar(entityLocation, entitySize, movement)
{
}

/**
 * @brief destructor van FuelcarSFML.
 */
RF_GUI::FuelcarSFML::~FuelcarSFML() = default;

/**
 * @brief functie die een FuelcarSFML tekent.
 */
void RF_GUI::FuelcarSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/fuel_car.png");

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
