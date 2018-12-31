
#ifndef ROAD_FIGHTER_FINISH_H
#define ROAD_FIGHTER_FINISH_H

#include "roadfighter/include/Road.h"

namespace RF {

    class Finish : public RF::Road {

    public:
        Finish();

        ~Finish() override;

        Finish(location &entityLocation, size &entitySize, movementVector &movement);

    };

}

#endif //ROAD_FIGHTER_FINISH_H
