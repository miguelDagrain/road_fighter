
#include "roadfighter_GUI/include/PassingcarSFML.h"

void RF_GUI::Passingcar::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/passing_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
