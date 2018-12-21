
#include <include/PlayerSFML.h>

#include "roadfighter_GUI/include/PlayerSFML.h"

RF_GUI::PlayerSFML::PlayerSFML(std::shared_ptr<RF::Player> basis):
        RF::Player(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement()))
{
}

void RF_GUI::PlayerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/player_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}

