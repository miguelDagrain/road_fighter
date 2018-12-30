

#include "roadfighter_GUI/include/Interface.h"

double get_line_end_of_road(std::string inputFile){
    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile(inputFile);

    int number = 0;

    int iter = 10;
    for(auto x:inputFile){

        if(x < 58 && x > 47){

            x -= 48;

            number += x;

            number *= iter;
        }

    }

    number /= 10;

    double endLine = (static_cast<double>(number)/backgroundTexture.getSize().x)*4;


    return endLine;
}

RF::World Interface::setupWorld(std::string &inputFile)
{
    RF::World road;

    std::shared_ptr<RF::SemiObserverWorld > observer = std::make_shared<RF::SemiObserverWorld>();
    road.setObserver(std::move(observer));

    double line = get_line_end_of_road(inputFile);

    RF::endOfRoad = line;

    Factory fact;

    std::shared_ptr<RF_GUI::RoadSFML> background = fact.createRoad(inputFile, 1);
    road.addObject(background);

    std::shared_ptr<RF_GUI::RoadSFML> backgroundMiddle = fact.createRoad(inputFile, 2);
    road.addObject(backgroundMiddle);


    RF::location loc(0, 2);
    RF::movementVector movement(0, 0);

    std::shared_ptr<RF_GUI::PlayerSFML > playerSFML = fact.createPlayer(loc, movement);

    road.addObject(playerSFML);

    return road;
}

void Interface::updateWorld(RF::World &road, std::string &inputFile)
{
    Interface::handleKeyboardInput(road);

    Factory fact;


    RF::location loc(0, 0);
    if(road.getObserver()->checkEndWorld() != loc){

        Interface::createEntities(road);


        std::shared_ptr<RF_GUI::RoadSFML> backgroundAbove = fact.createRoad(inputFile, road.getObserver()->checkEndWorld());
        road.addObject(backgroundAbove);

        road.getObserver()->resetEndWorld();
    }

    road.update();

}

void Interface::handleEvents()
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

void Interface::handleKeyboardInput(RF::World &road) {
    auto transformationObject = RF_GUI::Transformation::getInstance();

    RF::movementVector acceleration{0, 0};



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        acceleration.first -= 0.01;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        acceleration.first += 0.01;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        acceleration.second -= 0.002;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        acceleration.second += 0.002;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    }

    road.accelerate(acceleration);
}


void Interface::createEntities(RF::World &road)
{

    Factory fact;
    auto random = RF::Random::getInstance();

    for(int iter = 0; iter < 6; ++iter) {

        std::shared_ptr<RF::Entity > car = nullptr;

        int chance = random->getRandomInt();

        //neem een willekeurige waarde die de chance moet voldoen om een entity te maken (anders wordt het te vol)
        if(chance == 4){

            RF::location startpoint(random->getDoubleOnRoad(), random->getDoubleOnNextPiece());

            //als we een entity maken, moeten we nog bepalen welke auto wordt gepasseerd
            int kindOfCar = random->getIntCar();

            if(kindOfCar < 8){
                car = fact.createPassingcar(startpoint);
            }else{
                car = fact.createFuelcar(startpoint);
            }
        }

        if(car) {
            road.addObject(car);
        }
    }
}