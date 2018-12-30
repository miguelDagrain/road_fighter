
#include <roadfighter/include/SemiObserverWorld.h>

#include "roadfighter/include/SemiObserverWorld.h"

RF::SemiObserverWorld::SemiObserverWorld(): existPlayer(false)
{
    RF::location loc(0, 0);
    endWorld = loc;
}

RF::SemiObserverWorld::~SemiObserverWorld() = default;


void RF::SemiObserverWorld::notifyEndWorld(const RF::location &loc)
{
    endWorld = loc;
}

void RF::SemiObserverWorld::resetEndWorld()
{
    RF::location loc(0, 0);
    endWorld = loc;
}

const RF::location RF::SemiObserverWorld::checkEndWorld() {
    return endWorld;
}

void RF::SemiObserverWorld::notifyExistPlayer() {
    existPlayer = true;
}

void RF::SemiObserverWorld::resetExistPlayer() {
    existPlayer = false;
}

bool RF::SemiObserverWorld::checkExistPlayer() {
    return existPlayer;
}
