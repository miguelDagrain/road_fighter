

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <SFML/Graphics.hpp>

#include "roadfighter/include/Entity.h"


using exactLocation = std::pair<int, int>;


namespace RF_GUI {

    sf::RenderWindow window(sf::VideoMode(700, 700), "roadfighter");

    class Transformation {
    public:

        static Transformation &getInstance();

        Transformation(Transformation const &) = delete;

        void operator=(Transformation const &) = delete;

        exactLocation operator()(const RF::location &loc, const int x, const int y);

    private:

        Transformation() = default;
    };

}


#endif //ROAD_FIGHTER_TRANSFORMATION_H
