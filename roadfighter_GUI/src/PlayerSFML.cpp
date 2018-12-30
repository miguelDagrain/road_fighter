
#include "roadfighter_GUI/include/PlayerSFML.h"

RF_GUI::PlayerSFML::PlayerSFML() = default;

RF_GUI::PlayerSFML::PlayerSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement):
        RF::Player(entityLocation, entitySize, movement)
{
}

RF_GUI::PlayerSFML::~PlayerSFML() = default;

void RF_GUI::PlayerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("sprites/player_car.png");

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

