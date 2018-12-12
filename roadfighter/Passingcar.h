

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H

#include <Entity.h>

namespace RF {

    class Passingcar : public Entity{

    public:
        Passingcar() = default;

        Passingcar(location& entityLocation, size& entitySize);

    };

}

#endif //ROAD_FIGHTER_PASSINGCAR_H
