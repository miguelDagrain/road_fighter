

#ifndef ROAD_FIGHTER_OBSERVEWORLD_H
#define ROAD_FIGHTER_OBSERVEWORLD_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class SemiObserverWorld {

    public:
        SemiObserverWorld();

        ~SemiObserverWorld();

        void notifyEndWorld(const RF::location &loc);

        void resetEndWorld();

        const RF::location checkEndWorld();
    private:

        RF::location endWorld;
    };

}

#endif //ROAD_FIGHTER_OBSERVEWORLD_H
