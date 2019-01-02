#include "roadfighter_GUI/include/BulletSFML.h"

/**
 * @brief basis constructor voor een BulletSFML.
 */
RF_GUI::BulletSFML::BulletSFML() = default;

/**
 * @brief constructor voor BulletSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van BulletSFML.
 * @param entitySize grootte van BulletSFML.
 * @param movement beweging van BulletSFML.
 */
RF_GUI::BulletSFML::BulletSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
        Bullet(entityLocation, entitySize, movement)
{
}

/**
 * @brief destructor van BulletSFML.
 */
RF_GUI::BulletSFML::~BulletSFML() = default;

/**
 * @brief functie die een BulletSFML tekent.
 */
void RF_GUI::BulletSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/bullet.png");

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

