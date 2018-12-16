
#include "roadfighter_GUI/include/BulletSFML.h"

void RF_GUI::BulletSFML::draw() {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("../sprites/bullet.png");


    sprite.setTexture(texture);
}
