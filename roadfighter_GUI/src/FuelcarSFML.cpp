
#include <include/FuelcarSFML.h>

#include "roadfighter_GUI/include/FuelcarSFML.h"

RF_GUI::FuelcarSFML::FuelcarSFML(std::shared_ptr<RF::Fuelcar> basis):
RF::Fuelcar(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement()))
{

}

void RF_GUI::FuelcarSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/fuel_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
