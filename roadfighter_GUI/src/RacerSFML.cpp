
#include "roadfighter_GUI/include/RacerSFML.h"

void RF_GUI::RacerSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/racing_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
