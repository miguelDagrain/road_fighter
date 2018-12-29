
#include "roadfighter_GUI/include/RacerSFML.h"

RF_GUI::RacerSFML::RacerSFML() = default;

RF_GUI::RacerSFML::RacerSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement) :
RF::Racer(entityLocation, entitySize, movement)
{
}

RF_GUI::RacerSFML::~RacerSFML() = default;

void RF_GUI::RacerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/racing_car.png");

    sprite.setTexture(texture);

    sf::Vector2u sizeTexture = texture.getSize();

    auto scaleX = static_cast<float >(this->getSize().first/sizeTexture.x);
    auto scaleY = static_cast<float >(this->getSize().second/sizeTexture.y);

    sprite.scale(scaleX, scaleY);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    auto transform = Transformation::getInstance();

    (*transform)(sprite);
}
