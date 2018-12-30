

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

        void notifyExistPlayer();

        void resetExistPlayer();

        bool checkExistPlayer();

    private:

        bool existPlayer;

        RF::location endWorld;
    };

}

#endif //ROAD_FIGHTER_OBSERVEWORLD_H
