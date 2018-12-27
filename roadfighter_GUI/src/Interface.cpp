
#include "roadfighter_GUI/include/Interface.h"

void RF_GUI::Interface::handleEvents()
{
    auto transformationObject = RF_GUI::Transformation::getInstance();

    sf::Event event {};
    while(transformationObject->getWindow()->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed :
                transformationObject->getWindow()->close();
                break;

            default:
                break;
        }
    }

}

void RF_GUI::Interface::handleKeyboardInput(RF::World &road)
{
    auto transformationObject = RF_GUI::Transformation::getInstance();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        road;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

}