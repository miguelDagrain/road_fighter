

#ifndef ROAD_FIGHTER_INTERFACE_H
#define ROAD_FIGHTER_INTERFACE_H

#include <fstream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "roadfighter/include/World.h"
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/ObserverWorld.h"
#include "roadfighter/include/Random.h"

#include "Factory.h"
#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter_GUI/include/RoadSFML.h"


    class Interface {
    public:

        explicit Interface(int roadLength);

        ~Interface();

        void runGame(std::string &&inputfileRoad, std::string &&inputFileFinish);

    private:

        RF::World setupWorld(std::string &inputFileRoad);

        bool updateWorld(RF::World &road,std::string &inputFileRoad, std::string &inputFileFinish);

        void handleEvents(sf::View &gameView);

        void handleKeyboardInput(RF::World &road);

        void createFPCars(RF::World &road);

        void createRacerCars(RF::World &road);


        int coolDown;

        int length;
    };



#endif //ROAD_FIGHTER_INTERFACE_H
