
#include "roadfighter_GUI/include/FuelcarSFML.h"

void RF_GUI::FuelcarSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/fuel_car.png");

    sprite.setTexture(texture);

    sprite.setPosition(static_cast<float >(getLocation().first), static_cast<float >(getLocation().second));

    window.draw(sprite);
}
