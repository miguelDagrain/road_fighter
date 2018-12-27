
#include <include/RoadSFML.h>

#include "roadfighter_GUI/include/RoadSFML.h"

RF_GUI::RoadSFML::RoadSFML(std::shared_ptr<RF::Road> basis, std::string &textureFile):
RF::Road(const_cast<RF::location&>(basis->getLocation()), const_cast<RF::size&>(basis->getSize()), const_cast<RF::movementVector&>(basis->getMovement())),
textureFile(textureFile)
{
}

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


