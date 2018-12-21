//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Bullet.h"


namespace RF_GUI {

    class BulletSFML : public RF::Bullet{

        BulletSFML(std::shared_ptr<RF::Bullet> basis);

        void draw() final;
    };

}
#endif //ROAD_FIGHTER_BULLETSFML_H
