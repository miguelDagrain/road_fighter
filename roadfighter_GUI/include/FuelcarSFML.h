
#ifndef ROAD_FIGHTER_FUELCARSFML_H
#define ROAD_FIGHTER_FUELCARSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Fuelcar.h"

namespace RF_GUI {

    class FuelcarSFML : public RF::Fuelcar {

    public:
        FuelcarSFML();

        FuelcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement);

        ~FuelcarSFML() override;

        void draw() final;

    };

}


#endif //ROAD_FIGHTER_FUELCARSFML_H
