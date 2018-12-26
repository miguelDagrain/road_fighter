

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "roadfighter/include/Entity.h"


using exactLocation = std::pair<int, int>;


namespace RF_GUI {

    class Transformation {

    public:

        ~Transformation() = default;

        static std::shared_ptr<Transformation > &getInstance();

        void operator()(sf::Sprite entity);

        std::shared_ptr< sf::RenderWindow > getWindow();

    private:

        static std::shared_ptr<RF_GUI::Transformation > instance;

        std::shared_ptr< sf::RenderWindow> window;

        Transformation();
    };

}



#endif //ROAD_FIGHTER_TRANSFORMATION_H
