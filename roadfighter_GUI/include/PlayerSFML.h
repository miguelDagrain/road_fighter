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

        explicit PlayerSFML(std::shared_ptr<RF::Player > basis);

        ~PlayerSFML() override = default;

        void draw() final;

    };

}

#endif //ROAD_FIGHTER_PLAYERSFML_H
