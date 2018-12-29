
#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Bullet.h"


namespace RF_GUI {

    class BulletSFML : public RF::Bullet{

    public:

        BulletSFML();

        BulletSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement);

        ~BulletSFML() override;

        void draw() final;
    };

}
#endif //ROAD_FIGHTER_BULLETSFML_H
