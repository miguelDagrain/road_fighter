
#include <include/BulletSFML.h>

#include "roadfighter_GUI/include/BulletSFML.h"


RF_GUI::BulletSFML::BulletSFML(std::shared_ptr<RF::Bullet> basis):
        Bullet(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement()))
{
}

void RF_GUI::BulletSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/bullet.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}

