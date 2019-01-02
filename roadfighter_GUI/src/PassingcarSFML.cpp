#include "roadfighter_GUI/include/PassingcarSFML.h"

/**
 * @brief basis constructor voor een PassingcarSFML.
 */
RF_GUI::PassingcarSFML::PassingcarSFML() = default;

/**
 * @brief constructor voor PassingcarSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van PassingcarSFML.
 * @param entitySize grootte van PassingcarSFML.
 * @param movement beweging van PassingcarSFML.
 */
RF_GUI::PassingcarSFML::PassingcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
RF::Passingcar(entityLocation, entitySize, movement)
{
}

/**
 * @brief destructor van PassingcarSFML.
 */
RF_GUI::PassingcarSFML::~PassingcarSFML() = default;

/**
 * @brief functie die een PassingcarSFML tekent.
 */
void RF_GUI::PassingcarSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/passing_car.png");

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
