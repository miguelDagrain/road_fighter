

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

RF::World RF_GUI::Interface::setupWorld(std::string inputFile)
{
    RF::World road;

    //de naam van de inputfile moet aangeven waar de lijn eindigt
    int end_line_of_road = get_line_end_of_road(inputFile);

    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile(inputFile);

    RF::location locationRoad(-4,-3);
    RF::size sizeRoad(backgroundTexture.getSize().x, backgroundTexture.getSize().y);
    RF::movementVector movementRoad(0, 0);

    RF_GUI::RoadSFML background(locationRoad, sizeRoad, movementRoad, inputFile);

//    background.scale(static_cast<float >(800.0/294), static_cast<float >(600.0/164));

    road.addObject(std::make_shared<RF_GUI::RoadSFML>(background));

    return road;
}


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

void RF_GUI::Interface::handleKeyboardInput(RF::World &road) {
    auto transformationObject = RF_GUI::Transformation::getInstance();

    RF::movementVector acceleration{0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        acceleration.first -= 0.001;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        acceleration.first += 0.001;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        acceleration.second -= 0.001;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        acceleration.second += 0.001;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
    }

    road.setMovement(acceleration);
}