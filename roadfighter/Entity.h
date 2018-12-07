#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include <utility>


using location = std::pair<double, double>;
using size = location;

namespace RF {

    class Entity {

    public:
        virtual Entity() = default;

        Entity(location& loc, size& entitySize);




    private:
        location location;
        size entitySize;

        double speed;

    };


}


#endif //ROAD_FIGHTER_ENTITY_H
