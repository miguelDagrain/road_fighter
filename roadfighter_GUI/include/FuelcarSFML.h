//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_FUELCARSFML_H
#define ROAD_FIGHTER_FUELCARSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Fuelcar.h"

namespace RF_GUI {

    class FuelcarSFML : public RF::Fuelcar {

        FuelcarSFML(std::shared_ptr<RF::Fuelcar > basis);

        void draw() final;

    };

}

#endif //ROAD_FIGHTER_FUELCARSFML_H
