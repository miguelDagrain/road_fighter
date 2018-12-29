
#ifndef ROAD_FIGHTER_PASSINGCARSFML_H
#define ROAD_FIGHTER_PASSINGCARSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Passingcar.h"

namespace RF_GUI {

    class PassingcarSFML : public RF::Passingcar {

    public:
        PassingcarSFML();

        PassingcarSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement);

        ~PassingcarSFML() override;

        void draw() final;

    };

}

#endif //ROAD_FIGHTER_PASSINGCARSFML_H
