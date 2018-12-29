
#include "roadfighter_GUI/include/RoadSFML.h"

RF_GUI::RoadSFML::RoadSFML() = default;

RF_GUI::RoadSFML::RoadSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement,std::string &textureFile):
RF::Road(entityLocation, entitySize, movement), textureFile(textureFile)
{
}

RF_GUI::RoadSFML::~RoadSFML() = default;

void RF_GUI::RoadSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(this->textureFile);

    sprite.setTexture(texture);

    sf::Vector2u sizeTexture = texture.getSize();

    auto scaleX = static_cast<float >(this->getSize().first/sizeTexture.x);
    auto scaleY = static_cast<float >(this->getSize().second/sizeTexture.y);

    sprite.scale(scaleX, scaleY);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    auto transform = Transformation::getInstance();

    (*transform)(sprite);
}



