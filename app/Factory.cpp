#include "app/Factory.h"

/**
 * @brief basis constructor voor een Factory.
 */
Factory::Factory() = default;

/**
 * @brief destructor voor een Factory.
 */
Factory::~Factory() = default;

/**
 * @brief functie om een kogel aan te maken.
 *
 * @param base ptr naar een entiteit.
 * @return een bullet gemaakt aan de hand van de entiteit.
 */
std::shared_ptr<RF_GUI::BulletSFML> Factory::createBullet(std::shared_ptr<RF::Entity > base)
{
    RF::location standardLoc(base->getLocation());
    RF::size standardSize(base->getSize());
    RF::movementVector standardMovement(base->getMovement());

    return std::make_shared<RF_GUI::BulletSFML >(standardLoc, standardSize, standardMovement);
}

/**
 * @brief functie om een FuelcarSFML aan te maken.
 *
 * @param entityLocation locatie van de FuelcarSFML.
 * @return shared ptr naar de nieuw aangemaakte entiteit.
 */
std::shared_ptr<RF_GUI::FuelcarSFML > Factory::createFuelcar(RF::location &entityLocation)
{
    RF::size standard(0.4, 0.4);
    RF::movementVector speed(0, -0.05);

    return std::make_shared<RF_GUI::FuelcarSFML >(entityLocation, standard, speed);
}

/**
 * @brief functie om een PassingcarSFML aan te maken.
 *
 * @param entityLocation locatie van de PassingcarSFML.
 * @return shared ptr naar de nieuw aangemaakte entiteit.
 */
std::shared_ptr<RF_GUI::PassingcarSFML > Factory::createPassingcar(RF::location &entityLocation)
{
    RF::size standard(0.4, 0.4);
    RF::movementVector speed(0, -0.05);

    return std::make_shared<RF_GUI::PassingcarSFML >(entityLocation, standard, speed);
}

/**
 * @brief functie om een PlayerSFML aan te maken.
 *
 * @param entityLocation locatie van de PlayerSFML.
 * @param movement beweging van de PlayerSFML.
 * @return shared ptr naar de nieuw aangemaakte PlayerSFML.
 */
std::shared_ptr<RF_GUI::PlayerSFML > Factory::createPlayer(RF::location &entityLocation, RF::movementVector &movement)
{
    RF::size standard(0.4, 0.4);

    return std::make_shared<RF_GUI::PlayerSFML >(entityLocation, standard, movement);
}

/**
 * @brief functie om een RacerSFML aan te maken.
 *
 * @param entityLocation locatie van de RacerSFML.
 * @param movement beweging van de RacerSFML.
 * @return shared ptr naar de nieuw aangemaakte RacerSFML.
 */
std::shared_ptr<RF_GUI::RacerSFML > Factory::createRacer(RF::location &entityLocation, RF::movementVector &movement)
{
    RF::size standard(0.4, 0.4);

    return std::make_shared<RF_GUI::RacerSFML >(entityLocation, standard, movement);
}

/**
 * @brief functie om een RoadSFML aan te maken.
 *
 * @param inputFile bestand waar we de texture voor het wegstuk kunnen vinden.
 * @param pos positie waar de wegdek moet worden geplaatst, komt overeen met een standaardlocatie.
 * @return shared ptr naar de nieuw aangemaakte RoadSFML.
 */
std::shared_ptr<RF_GUI::RoadSFML > Factory::createRoad(std::string &inputFile, int pos)
{
    RF::location standardLocation;
    if(pos == 1){
        standardLocation.first = -4;
        standardLocation.second = -3;
    }else if(pos == 2){
        standardLocation.first = -4;
        standardLocation.second = -9;
    }else{
        throw RF::RoadfighterError("road must be build on pos 1 or 2.");
    }

    RF::size standardSize(8, 6);
    RF::movementVector standardMovement(0, 0);

    return std::make_shared<RF_GUI::RoadSFML >(standardLocation, standardSize, standardMovement, inputFile);
}

/**
 * @brief functie om een RoadSFML aan te maken.
 *
 * @param inputFile bestand waar we de texture voor het wegstuk kunnen vinden.
 * @param loc locatie van de verwijderde RoadSFML.
 * @return shared ptr naar de nieuw aangemaakte RoadSFML.
 */
std::shared_ptr<RF_GUI::RoadSFML> Factory::createRoad(std::string &inputFile, const RF::location &loc)
{

    RF::location newLoc(loc.first, loc.second - 12);
    RF::size standardSize(8, 6);
    RF::movementVector standardMovement(0, 0);

    return std::make_shared<RF_GUI::RoadSFML >(newLoc, standardSize, standardMovement, inputFile);

}

/**
 * @brief functie om een FinishSFML aan te maken.
 *
 * @param inputFile bestand waar we de texture voor het wegstuk met finishline kunnen vinden.
 * @param loc locatie van de verwijderde RoadSFML.
 * @return shared ptr naar de nieuw aangemaakte FinishSFML.
 */
std::shared_ptr<RF_GUI::FinishSFML> Factory::createFinish(std::string &inputFile, const RF::location &loc)
{
    RF::location newLoc(loc.first, loc.second - 12);
    RF::size standardSize(8, 6);
    RF::movementVector standardMovement(0, 0);

    return std::make_shared<RF_GUI::FinishSFML >(newLoc, standardSize, standardMovement, inputFile);
}
