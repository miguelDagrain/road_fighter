
#include <include/PassingcarSFML.h>

#include "roadfighter_GUI/include/PassingcarSFML.h"

RF_GUI::PassingcarSFML::PassingcarSFML() = default;

RF_GUI::PassingcarSFML::PassingcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
RF::Passingcar(entityLocation, entitySize, movement)
{
}

RF_GUI::PassingcarSFML::~PassingcarSFML() = default;

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
