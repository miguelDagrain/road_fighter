
#include <include/RacerSFML.h>

#include "roadfighter_GUI/include/RacerSFML.h"

RF_GUI::RacerSFML::RacerSFML(std::shared_ptr<RF::Racer> basis) :
RF::Racer(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement()))
{
}

void RF_GUI::RacerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/racing_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
