
#include "roadfighter_GUI/include/FuelcarSFML.h"

RF_GUI::FuelcarSFML::FuelcarSFML() = default;

RF_GUI::FuelcarSFML::FuelcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
RF::Fuelcar(entityLocation, entitySize, movement)
{
}

RF_GUI::FuelcarSFML::~FuelcarSFML() = default;

void RF_GUI::FuelcarSFML::draw()
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/fuel_car.png");

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
