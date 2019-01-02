
#include "app/Factory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"

/**
 * @brief basis constructor voor een PlayerSFML.
 */
RF_GUI::PlayerSFML::PlayerSFML() = default;

/**
 * @brief constructor voor PlayerSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van PlayerSFML.
 * @param entitySize grootte van PlayerSFML.
 * @param movement beweging van PlayerSFML.
 */
RF_GUI::PlayerSFML::PlayerSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
        RF::Player(entityLocation, entitySize, movement)
{
}

/**
 * @brief destructor van PlayerSFML.
 */
RF_GUI::PlayerSFML::~PlayerSFML() = default;

/**
 * @brief functie die een PlayerSFML tekent.
 */
void RF_GUI::PlayerSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/player_car.png");

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
