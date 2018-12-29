
#include "roadfighter/include/SemiObserverWorld.h"

RF::SemiObserverWorld::SemiObserverWorld()
{
    RF::location loc(0, 0);
    endWorld = loc;
}

RF::SemiObserverWorld::~SemiObserverWorld()
{
}

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
