

#ifndef ROAD_FIGHTER_INTERFACE_H
#define ROAD_FIGHTER_INTERFACE_H

#include <SFML/Graphics.hpp>

#include "roadfighter/include/World.h"
#include "roadfighter_GUI/include/Transformation.h"

namespace RF_GUI {
    namespace Interface {
        void setupWorld(RF::World &world);

        void handleEvents();

        void handleKeyboardInput(RF::World &road);
    };
}


#endif //ROAD_FIGHTER_INTERFACE_H
