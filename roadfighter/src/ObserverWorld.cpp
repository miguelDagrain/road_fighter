#include "roadfighter/include/ObserverWorld.h"

/**
 * @brief basis constructor van de ObserverWorld.
 */
RF::ObserverWorld::ObserverWorld(): existPlayer(false), score(0), timeScore(10000), finished(false)
{
    RF::location loc(0, 0);
    endWorld = loc;
}

/**
 * @brief destructor van een ObserverWorld.
 */
RF::ObserverWorld::~ObserverWorld() = default;

/**
 * @brief functie die de observer op de hoogte stelt dat er een nieuw stuk weg moet aangemaakt worden.
 *
 * @param loc locatie waar van het stuk weg is verwijderd.
 */
void RF::ObserverWorld::notifyEndWorld(const RF::location &loc)
{
    endWorld = loc;
}

/**
 * @brief functie die de de observer reset voor het einde van een stuk weg.
 */
void RF::ObserverWorld::resetEndWorld()
{
    RF::location loc(0, 0);
    endWorld = loc;
}

/**
 * @brief functie die controleert of er een stuk weg is verwijderd.
 *
 * @return de locatie waar het stuk weg is verwijderd,
 * loc(0, 0) betekent dat er geen stuk weg is verwijderd.
 */
const RF::location RF::ObserverWorld::checkEndWorld() {
    return endWorld;
}

/**
 * @brief functie die de observer op de hoogte stelt dat de speler is gecrasht.
 */
void RF::ObserverWorld::notifyExistPlayer() {
    existPlayer = true;
}

/**
 * @brief functie die het onbestaan van de speler reset.
 */
void RF::ObserverWorld::resetExistPlayer() {
    existPlayer = false;
}

/**
 * @brief functie die controleert of de speler nog bestaat.
 *
 * @return het al dan niet onbestaan van de speler.
 */
bool RF::ObserverWorld::checkExistPlayer() {
    return existPlayer;
}

/**
 * @brief functie die aangeeft dat er weer een bepaalde tijd is verstreken, belangrijk voor de tijdscore
 */
void RF::ObserverWorld::notifyTimePassed() {
    timeScore = long(timeScore*0.9999);
}

/**
 * @brief functie die aangeeft dat een entiteit is geschoten.
 */
void RF::ObserverWorld::notifyShotEntity() {
    score += 100;
}

/**
 * @brief functie die aangeeft dat de speler is gecrasht.
 */
void RF::ObserverWorld::notifyCrashed() {
    score -= 200;
}

/**
 * @brief functie die de observer op de hoogte stelt dat de speler is gefinished
 */
void RF::ObserverWorld::notifyFinished() {
    finished = true;
    score += timeScore;
}

/**
 * @brief functie die controleert of de speler is gefinished.
 *
 * @return of de speler al dan niet is gefinished.
 */
bool RF::ObserverWorld::checkFinished() {
    return finished;
}

/**
 * @brief functie die de score controleert.
 *
 * @return de score die op dit moment al is behaald.
 */
long RF::ObserverWorld::checkScore() {
    return score;
}
