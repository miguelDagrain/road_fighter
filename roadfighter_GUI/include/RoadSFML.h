

#ifndef ROAD_FIGHTER_ROADSFML_H
#define ROAD_FIGHTER_ROADSFML_H


#include "roadfighter/include/Road.h"

#include "roadfighter_GUI/include/Transformation.h"

namespace RF_GUI {

    class RoadSFML : public RF::Road {

    public:
        RoadSFML();

        RoadSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement, std::string &textureFile);

        ~RoadSFML() override;

        void draw() final;

    private:

        std::string textureFile;
    };
}

#endif //ROAD_FIGHTER_ROADSFML_H
