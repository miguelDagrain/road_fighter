
#include <include/PassingcarSFML.h>

#include "roadfighter_GUI/include/PassingcarSFML.h"


RF_GUI::PassingcarSFML::PassingcarSFML(std::shared_ptr<RF::Passingcar > basis):
RF::Passingcar(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement()))
{

}


void RF_GUI::PassingcarSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/passing_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
