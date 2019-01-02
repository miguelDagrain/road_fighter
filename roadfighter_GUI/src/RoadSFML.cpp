#include "roadfighter_GUI/include/RoadSFML.h"

/**
 * @brief basis constructor voor een RoadSFML.
 */
RF_GUI::RoadSFML::RoadSFML() = default;

/**
 * @brief constructor voor RoadSFML met locatie, grootte en beweging.
 *
 * @param entityLocation locatie van RoadSFML.
 * @param entitySize grootte van RoadSFML.
 * @param movement beweging van RoadSFML.
 */
RF_GUI::RoadSFML::RoadSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement,std::string &textureFile):
RF::Road(entityLocation, entitySize, movement), textureFile(textureFile)
{
}

/**
 * @brief destructor van RoadSFML.
 */
RF_GUI::RoadSFML::~RoadSFML() = default;

/**
 * @brief functie die een RoadSFML tekent.
 */
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



