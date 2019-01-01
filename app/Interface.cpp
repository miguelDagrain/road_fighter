

#include <app/Interface.h>

#include "Interface.h"

long get_number_from_string(const std::string &inputFile){
    long number = 0;

    for(auto x:inputFile){

        if(x < 58 && x > 47){

            x -= 48;

            number += x;

            number *= 10;
        }

    }

    number /= 10;

    return number;
}

double get_line_end_of_road(const std::string &inputFile){
    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile(inputFile);

    long number = get_number_from_string(inputFile);

    double endLine = (static_cast<double>(number)/backgroundTexture.getSize().x)*4;


    return endLine;
}

Interface::Interface(int roadLength): coolDown(0), length(roadLength)
{
}

Interface::~Interface() = default;


RF::World Interface::setupWorld(std::string &inputFileRoad)
{
    RF::World road;

    std::shared_ptr<RF::ObserverWorld > observer = std::make_shared<RF::ObserverWorld>();
    road.setObserver(std::move(observer));

    double line = get_line_end_of_road(inputFileRoad);

    RF::endOfRoad = line;

    Factory fact;

    std::shared_ptr<RF_GUI::RoadSFML> background = fact.createRoad(inputFileRoad, 1);
    road.addObject(background);

    background = fact.createRoad(inputFileRoad, 2);
    road.addObject(background);


    createRacerCars(road);


    RF::location loc(0, 2);
    RF::movementVector movement(0, 0);

    std::shared_ptr<RF_GUI::PlayerSFML > playerSFML = fact.createPlayer(loc, movement);

    road.addObject(playerSFML);

    return road;
}

bool Interface::updateWorld(RF::World &road, std::string &inputFileRoad, std::string &inputFileFinish)
{
    Interface::handleKeyboardInput(road);

    Factory fact;

    road.update();

    RF::location standardLoc(0, 0);
    if(road.getObserver()->checkEndWorld() != standardLoc){

        Interface::createFPCars(road);


        if(length == 1){
            std::shared_ptr<RF_GUI::FinishSFML> backgroundFinish = fact.createFinish(inputFileFinish, road.getObserver()->checkEndWorld());
            road.addObject(backgroundFinish);
        }else {
            std::shared_ptr<RF_GUI::RoadSFML> background = fact.createRoad(inputFileRoad, road.getObserver()->checkEndWorld());
            road.addObject(background);
            --length;
        }
        road.getObserver()->resetEndWorld();
    }

    if(road.getObserver()->checkExistPlayer()){
        RF::location locPlayer(0, 2);
        RF::movementVector movement(0, 0);

        std::shared_ptr<RF_GUI::PlayerSFML > playerSFML = fact.createPlayer(locPlayer, movement);
        road.addObject(playerSFML);

        road.getObserver()->resetExistPlayer();
    }

    //we controleren of we gefinished zijn
    return road.getObserver()->checkFinished();

}

void Interface::handleEvents(sf::View &gameView, sf::View &scoreView)
{
    auto transformationObject = RF_GUI::Transformation::getInstance();

    sf::Event event {};
    while(transformationObject->getWindow()->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed :
                transformationObject->getWindow()->close();
                break;
            case sf::Event::Resized:
                gameView.reset(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height));
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

    road.accelerate(acceleration);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !coolDown){
        Factory fact;

        std::shared_ptr<RF::Entity > bulletBase = road.attackAction(road);
        road.addObject(fact.createBullet(bulletBase));
        coolDown = 100;
    }else {
        if(coolDown > 0) {
            --coolDown;
        }
    }
}


void Interface::createFPCars(RF::World &road)
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

void Interface::createRacerCars(RF::World &road)
{

    Factory fact;

    RF::location location1(-0.8, 2);
    RF::location location2(1.4, 1);
    RF::location location3(-1.6, 1);


    RF::movementVector movement1(0, -0.054);
    RF::movementVector movement2(0, -0.05);
    RF::movementVector movement3(0, -0.058);

    std::shared_ptr<RF_GUI::RacerSFML > racer = fact.createRacer(location1, movement1);
    road.addObject(racer);
    racer = fact.createRacer(location2, movement2);
    road.addObject(racer);
    racer = fact.createRacer(location3, movement3);
    road.addObject(racer);

}

void Interface::runGame(std::string &&inputfileRoad, std::string &&inputFileFinish)
{

    //we laden een font in om de score te schrijven
    sf::Font font;
    font.loadFromFile("slkscr.ttf");

    RF::World road = this->setupWorld(inputfileRoad);

    auto transformationObject = RF_GUI::Transformation::getInstance();

    sf::View gameView(sf::FloatRect(0.f, 0.f, transformationObject->getWindow()->getSize().x,
            transformationObject->getWindow()->getSize().y));

    sf::View viewScore(sf::FloatRect(0.f, 0.f, 100.f, 600.f));

    gameView.setViewport(sf::FloatRect(0.f, 0.f, 0.8f, 1.f));

    viewScore.setViewport(sf::FloatRect(0.8f, 0.f, 0.2f, 1.f));

    bool finished = false;

    while(transformationObject->getWindow()->isOpen() && !finished){
        this->handleEvents(gameView, viewScore);

        std::this_thread::sleep_for(std::chrono::microseconds(300));

        finished = this->updateWorld(road, inputfileRoad, inputFileFinish);

        transformationObject->getWindow()->clear();

        transformationObject->getWindow()->setView(gameView);

        road.draw();


        transformationObject->getWindow()->setView(viewScore);

        long currentScore = road.getObserver()->checkScore();

        sf::Text score;
        score.setFont(font);
        score.setString(std::to_string(currentScore));
        score.setCharacterSize(30);
        score.setFillColor(sf::Color::White);
        score.setStyle(sf::Text::Bold);
        score.setPosition(10, (40));


        transformationObject->getWindow()->draw(score);

        transformationObject->getWindow()->display();
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Finished");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(200, 0);

    std::ifstream highScores("All_time_high_scores.txt");

    long gottenScore = road.getObserver()->checkScore();

    std::vector<std::string > vecScores;
    std::string scoreStr;
    std::string replaced;
    while (getline(highScores, scoreStr)){
        long score = get_number_from_string(scoreStr);

        if(replaced.empty()) {
            if (score > gottenScore) {
                vecScores.emplace_back(scoreStr);
            } else {
                vecScores.emplace_back(std::to_string(gottenScore));
                replaced = scoreStr;

            }
        } else {
            vecScores.emplace_back(replaced);
            replaced = scoreStr;
        }
    }

    highScores.close();
    std::ofstream newHighScores("All_time_high_scores.txt", std::ios::trunc);

    std::vector<sf::Text > scores;
    int iter = 1;
    for(auto &scoreText:vecScores){
        newHighScores << scoreText;
        newHighScores.write("\n", 1);


        sf::Text score;
        score.setFont(font);
        score.setString(scoreText);
        score.setCharacterSize(30);
        score.setFillColor(sf::Color::White);
        score.setStyle(sf::Text::Bold);
        score.setPosition(200, (40*iter));

        scores.emplace_back(score);

        ++iter;
    };

    highScores.close();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    while(transformationObject->getWindow()->isOpen()){
        this->handleEvents(gameView, viewScore);

        transformationObject->getWindow()->setView(gameView);

        transformationObject->getWindow()->clear(sf::Color::Black);

        transformationObject->getWindow()->draw(text);

        for(auto &score:scores){
            transformationObject->getWindow()->draw(score);
        }

        transformationObject->getWindow()->display();
    }
}

