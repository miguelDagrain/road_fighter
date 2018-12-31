

#ifndef ROAD_FIGHTER_FINALSFML_H
#define ROAD_FIGHTER_FINALSFML_H

#include "roadfighter/include/Finish.h"
#include "roadfighter_GUI/include/Transformation.h"

namespace RF_GUI {

    class FinishSFML : public RF::Finish {

    public:
        FinishSFML();

        FinishSFML(RF::location &entityLocation, RF::size &entitySize, RF::movementVector &movement, std::string &textureFile);

        ~FinishSFML() override;

        void draw() final;

    private:

        std::string textureFile;
    };
}

#endif //ROAD_FIGHTER_FINALSFML_H
