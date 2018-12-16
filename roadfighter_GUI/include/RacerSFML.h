//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_RACERSFML_H
#define ROAD_FIGHTER_RACERSFML_H

#include "roadfighter/include/Racer.h"

namespace RF_GUI {

    class RacerSFML : public RF::Racer {

        void draw() final;

    };
}

#endif //ROAD_FIGHTER_RACERSFML_H
