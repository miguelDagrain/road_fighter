#include "roadfighter/include/Random.h"

namespace RF {
    std::shared_ptr<RF::Random > RF::Random::instance = nullptr;
    //volgens code inspection field instance is never used maar safe delete gaat niet want
    //hij wordt wel degelijk in de getInstance() functie gebruikt
}

/**
 * @brief functie die een instantie van de Random klasse teruggeeft.
 *
 * @return shared ptr naar de instantie van Random klasse.
 */
std::shared_ptr<RF::Random > &RF::Random::getInstance()
{
    if(instance == nullptr){

        auto random = new Random();

        instance = std::shared_ptr<RF::Random >(random);
    }

    return instance;
}

/**
 * @brief functie die een random int geeft om het soort wagen te kiezen.
 *
 * @return een int tussen 0 en 8.
 */
int RF::Random::getIntCar()
{
    std::uniform_int_distribution<int > distribution(0, 8);

    return distribution(engine);
}

/**
 * @brief functie die een random int teruggeeft om te bepalen of we een entity aanmaken.
 *
 * @return een int tussen 0 en 10.
 */
int RF::Random::getRandomInt() {
    std::uniform_int_distribution<int > distribution(0, 10);

    return distribution(engine);
};

/**
 * @brief functie die een random double teruggeeft om te bepalen waar de entity op de baan wordt gegenereerd.
 *
 * @return double tussen de twee lijnen.
 */
double RF::Random::getDoubleOnRoad()
{
    //de -0.4 is om geen auto over de witte lijn te creeren
    std::uniform_real_distribution<double > distribution(-RF::endOfRoad, RF::endOfRoad-0.4);

    return distribution(engine);
}

/**
 * @brief functie die een random double weergeeft om te bepalen waar op de weg een entiteit wordt gegenereerd.
 *
 * @return double tussen -6 en -3.4.
 */
double RF::Random::getDoubleOnNextPiece()
{
    std::uniform_real_distribution<double > distribution(-6, -3.4);

    return distribution(engine);
}

/**
 * @brief basis constructor voor een Random klasse.
 */
RF::Random::Random()
{
    engine = std::default_random_engine(randomizer());
}

