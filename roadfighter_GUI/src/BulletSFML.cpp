
#include <include/BulletSFML.h>

#include "roadfighter_GUI/include/BulletSFML.h"


RF_GUI::BulletSFML::BulletSFML() = default;

RF_GUI::BulletSFML::BulletSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
        Bullet(entityLocation, entitySize, movement)
{
}

RF_GUI::BulletSFML::~BulletSFML() = default;

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

    auto transform = Transformation::getInstance();

    (*transform)(sprite);
}

