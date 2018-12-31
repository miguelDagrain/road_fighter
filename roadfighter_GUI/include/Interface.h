

#ifndef ROAD_FIGHTER_INTERFACE_H
#define ROAD_FIGHTER_INTERFACE_H

#include <SFML/Graphics.hpp>

#include "roadfighter/include/World.h"
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/ObserverWorld.h"
#include "roadfighter/include/Random.h"

#include "roadfighter_GUI/include/SFMLFactory.h"
#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter_GUI/include/RoadSFML.h"


    namespace Interface {

        extern int coolDown;

        RF::World setupWorld(std::string &inputFile);

        void updateWorld(RF::World &road,std::string &inputFile);

        void handleEvents();

        void handleKeyboardInput(RF::World &road);

        void createFPCars(RF::World &road);

        void createRacerCars(RF::World &road);
    };



#endif //ROAD_FIGHTER_INTERFACE_H
