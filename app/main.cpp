
#include <iostream>

#include "include/SFMLFactory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "roadfighter_GUI/include/Interface.h"

void runGame(RF::World &road)
{

    auto transformationObject = RF_GUI::Transformation::getInstance();

    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));


    while(transformationObject->getWindow()->isOpen()){

        RF_GUI::Interface::handleKeyboardInput(road);

        road.update();

        transformationObject->getWindow()->clear();

        road.draw();

        transformationObject->getWindow()->setView(view);

        transformationObject->getWindow()->display();

        RF_GUI::Interface::handleEvents();

    }
}






int main(int argc, char* argv[]) {

    RF::World road = RF_GUI::Interface::setupWorld(argv[1]);

    runGame(road);

    return 0;
}