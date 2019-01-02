
#include "roadfighter_GUI/include/FinishSFML.h"

/**
 * @brief basis constructor voor een FinishSFML.
 */
RF_GUI::FinishSFML::FinishSFML() = default;

/**
 * @brief constructor voor FinishSFML met locatie, grootte, beweging en file waar we de texture kunnen vinden.
 *
 * @param entityLocation locatie van FinishSFML.
 * @param entitySize grootte van FinishSFML.
 * @param movement beweging van FinishSFML.
 * @param textureFile bestand waar we de texture kunnen vinden.
 */
RF_GUI::FinishSFML::FinishSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement,std::string &textureFile):
        RF::Finish(entityLocation, entitySize, movement), textureFile(textureFile)
{
}

/**
 * @brief destructor van FinishSFML.
 */
RF_GUI::FinishSFML::~FinishSFML() = default;

/**
 * @brief functie die een FinishSFML tekent.
 */
void RF_GUI::FinishSFML::draw() {
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



