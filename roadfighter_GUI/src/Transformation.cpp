
#include <include/Transformation.h>

#include "roadfighter_GUI/include/Transformation.h"

namespace RF_GUI{
    std::shared_ptr<RF_GUI::Transformation > Transformation::instance = nullptr;
}


RF_GUI::Transformation::Transformation(): window(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "roadfighter"))
{
}


void RF_GUI::Transformation::operator()(sf::Sprite entity) {
    if(entity.getPosition().x > 4 or entity.getPosition().x < -4 or entity.getPosition().y > 3 or entity.getPosition().y < -3){
        throw std::runtime_error("the given coordinates aren't within the correct range [-4, 4]x[-3, 3]");
    }

    //vergroot het object
    double xScale = ((entity.getScale().x/8.0)*window->getSize().x);
    double yScale = ((entity.getScale().y/6.0)*window->getSize().y);

    //herschaal de grootte van het object
    entity.setScale(static_cast<float >(xScale), static_cast<float >(yScale));

    //breng de coordinaten in het juiste kwadrant
    double xValue = entity.getPosition().x + 4;
    double yValue = entity.getPosition().y + 3;

    //herschaal de locatie van de coordinaten
    entity.setPosition(static_cast<float >((xValue/8.0)*window->getSize().x),
                       static_cast<float >((yValue/6.0)*window->getSize().y));



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
