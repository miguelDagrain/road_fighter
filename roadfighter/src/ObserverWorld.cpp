
#include <roadfighter/include/ObserverWorld.h>

#include "roadfighter/include/ObserverWorld.h"

RF::ObserverWorld::ObserverWorld(): existPlayer(false), score(0), timeScore(10000), finished(false)
{
    RF::location loc(0, 0);
    endWorld = loc;
}

RF::ObserverWorld::~ObserverWorld() = default;


void RF::ObserverWorld::notifyEndWorld(const RF::location &loc)
{
    endWorld = loc;
}

void RF::ObserverWorld::resetEndWorld()
{
    RF::location loc(0, 0);
    endWorld = loc;
}

const RF::location RF::ObserverWorld::checkEndWorld() {
    return endWorld;
}

void RF::ObserverWorld::notifyExistPlayer() {
    existPlayer = true;
}

void RF::ObserverWorld::resetExistPlayer() {
    existPlayer = false;
}

bool RF::ObserverWorld::checkExistPlayer() {
    return existPlayer;
}

void RF::ObserverWorld::notifyTimePassed() {
    timeScore = long(timeScore*0.99);
}

void RF::ObserverWorld::notifyShotEntity() {
    score += 100;
}

void RF::ObserverWorld::notifyCrashed() {
    score -= 200;
}

void RF::ObserverWorld::notifyFinished() {
    finished = true;
    score += timeScore;
}

long RF::ObserverWorld::checkScore() {
    return 0;
}

bool RF::ObserverWorld::checkFinished() {
    return finished;
}
