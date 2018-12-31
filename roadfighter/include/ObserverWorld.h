

#ifndef ROAD_FIGHTER_OBSERVEWORLD_H
#define ROAD_FIGHTER_OBSERVEWORLD_H

#include "roadfighter/include/Entity.h"

namespace RF {

    class ObserverWorld {

    public:
        ObserverWorld();

        ~ObserverWorld();

        void notifyEndWorld(const RF::location &loc);

        void resetEndWorld();

        const RF::location checkEndWorld();

        void notifyExistPlayer();

        void resetExistPlayer();

        bool checkExistPlayer();

        void notifyTimePassed();

        void notifyShotEntity();

        void notifyCrashed();

        void notifyFinished();

        long checkScore();

        bool checkFinished();

    private:

        bool existPlayer;

        RF::location endWorld;

        bool finished;

        long timeScore;
        long score;
    };

}

#endif //ROAD_FIGHTER_OBSERVEWORLD_H
