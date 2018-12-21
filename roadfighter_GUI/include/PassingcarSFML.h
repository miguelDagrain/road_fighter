//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_PASSINGCARSFML_H
#define ROAD_FIGHTER_PASSINGCARSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Passingcar.h"

namespace RF_GUI {

    class Passingcar : public RF::Passingcar {

        void draw() final;

    };

}

#endif //ROAD_FIGHTER_PASSINGCARSFML_H
