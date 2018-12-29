
#include <iostream>

#include "include/SFMLFactory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "roadfighter_GUI/include/Interface.h"

void runGame(std::string &&inputfile)
{

    RF::World road = Interface::setupWorld(inputfile);

    auto transformationObject = RF_GUI::Transformation::getInstance();

    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));


    while(transformationObject->getWindow()->isOpen()){

        Interface::updateWorld(road, inputfile);

        transformationObject->getWindow()->clear();

        road.draw();

        transformationObject->getWindow()->setView(view);

        transformationObject->getWindow()->display();

        Interface::handleEvents();

    }
}






int main(int argc, char* argv[]) {

    runGame(argv[1]);

    return 0;
}