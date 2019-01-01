//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_PLAYERSFML_H
#define ROAD_FIGHTER_PLAYERSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Player.h"

namespace RF_GUI {

    class PlayerSFML : public RF::Player {
    public:

        PlayerSFML();

        PlayerSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement);

        ~PlayerSFML() override;

        void draw() final;
    };

}

#endif //ROAD_FIGHTER_PLAYERSFML_H
