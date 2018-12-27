

#ifndef ROAD_FIGHTER_ROADSFML_H
#define ROAD_FIGHTER_ROADSFML_H

#include "roadfighter_GUI/include/Transformation.h"
#include "roadfighter/include/Road.h"

namespace RF_GUI {

    class RoadSFML : public RF::Road {

    public:

        RoadSFML(std::shared_ptr<RF::Road > basis, std::string &textureFile);

        RoadSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement, std::string &textureFile);

        ~RoadSFML() override;

        void draw() final;

    private:

        std::string textureFile;
    };
}

#endif //ROAD_FIGHTER_ROADSFML_H
