
#include <iostream>

#include "roadfighter/include/EntityFactory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "roadfighter_GUI/include/Interface.h"

int get_line_end_of_road(std::string inputFile){
    int number = 0;

    int iter = 1;
    for(auto x:inputFile){

        if(x < 58 && x > 47){
            number *= iter;

            x -= 47;

            number += x;
        }

        iter *= 10;
    }

    return number;
}


void runGame(std::string inputFile)
{
    RF::World road;

    auto transformationObject = RF_GUI::Transformation::getInstance();

    //de naam van de inputfile moet aangeven waar de lijn eindigt
    int end_line_of_road = get_line_end_of_road(inputFile);

    sf::Sprite background;
    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile(inputFile);

    sf::Vector2u sizeBackground = backgroundTexture.getSize();

    background.setTexture(backgroundTexture);

    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));

    background.scale(static_cast<float >(800.0/294), static_cast<float >(600.0/164));

    //create a player
    RF::Factory fact;

    RF::location loc(0, 0);
    RF::movementVector movement(0, 0);

    std::shared_ptr<RF::Player> player = fact.createPlayer(loc, movement);

    RF_GUI::PlayerSFML playerSFML(player);

    road.addObject(std::make_shared<RF_GUI::PlayerSFML>(playerSFML));

    while(transformationObject->getWindow()->isOpen()){

        RF_GUI::Interface::handleKeyboardInput(road);

        transformationObject->getWindow()->clear();

        transformationObject->getWindow()->draw(background);

        road.draw();

        transformationObject->getWindow()->setView(view);

        transformationObject->getWindow()->display();

        RF_GUI::Interface::handleEvents();

    }
}






int main(int argc, char* argv[]) {



    runGame(argv[1]);

    return 0;
}