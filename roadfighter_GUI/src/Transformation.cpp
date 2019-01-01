
#include <include/Transformation.h>

#include "roadfighter_GUI/include/Transformation.h"

namespace RF_GUI{
    std::shared_ptr<RF_GUI::Transformation > Transformation::instance = nullptr;
}


RF_GUI::Transformation::Transformation(): window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1000, 600), "roadfighter"))
{
}


void RF_GUI::Transformation::operator()(sf::Sprite entity) {
    //de 9 is om de weg op tijd te kunnen tekenen
    if(entity.getPosition().x > 4 || entity.getPosition().x < -4 || entity.getPosition().y > 3 || entity.getPosition().y < -9){
        throw std::runtime_error("the given coordinates aren't within the correct range [-4, 4]x[-3, 3]");
    }

    //vergroot het object
    float xScale = float((entity.getScale().x/8.0)*window->getSize().x);
    float yScale = float((entity.getScale().y/6.0)*window->getSize().y);

    //herschaal de grootte van het object
    entity.setScale(xScale, yScale);

    //breng de coordinaten in het juiste kwadrant
    float xValue = entity.getPosition().x + 4;
    float yValue = entity.getPosition().y + 3;

//    sf::FloatRect rect = entity.getGlobalBounds();
//    entity.setOrigin(rect.width /2 , rect.height / 2);

    //herschaal de locatie van de coordinaten
    entity.setPosition(float((xValue/8.0)*window->getSize().x), float((yValue/6.0)*window->getSize().y));

    window->draw(entity);
}

std::shared_ptr<RF_GUI::Transformation> &RF_GUI::Transformation::getInstance() {

    if(instance == nullptr) {

        auto transformation = new Transformation();

        instance = std::shared_ptr<RF_GUI::Transformation>(transformation);

    }

    return instance;
}

std::shared_ptr<sf::RenderWindow> RF_GUI::Transformation::getWindow() {
    return window;
}
