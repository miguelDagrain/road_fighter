
#include <include/SFMLFactory.h>

#include "roadfighter_GUI/include/SFMLFactory.h"

template<typename Tresult>
std::shared_ptr<Tresult> Factory::createEntity()
{
    auto newPtr = new Tresult();

    return std::make_shared<Tresult >(*newPtr);
}

std::shared_ptr<RF_GUI::BulletSFML> Factory::createBullet(RF::location &entityLocation, RF::movementVector &movement)
{
    RF::size standard(0.3, 0.3);

    return std::make_shared<RF_GUI::BulletSFML >(entityLocation, standard, movement);
}

std::shared_ptr<RF_GUI::FuelcarSFML > Factory::createFuelcar(RF::location &entityLocation)
{
    RF::size standard(0.4, 0.4);
    RF::movementVector speed(0, -0.05);

    return std::make_shared<RF_GUI::FuelcarSFML >(entityLocation, standard, speed);
}

std::shared_ptr<RF_GUI::PassingcarSFML > Factory::createPassingcar(RF::location &entityLocation)
{
    RF::size standard(0.4, 0.4);
    RF::movementVector speed(0, -0.05);

    return std::make_shared<RF_GUI::PassingcarSFML >(entityLocation, standard, speed);
}

std::shared_ptr<RF_GUI::PlayerSFML > Factory::createPlayer(RF::location &entityLocation, RF::movementVector &movement)
{
    RF::size standard(0.4, 0.4);

    return std::make_shared<RF_GUI::PlayerSFML >(entityLocation, standard, movement);
}

std::shared_ptr<RF_GUI::RacerSFML > Factory::createRacer(RF::location &entityLocation, RF::movementVector &movement)
{
    RF::size standard(0.4, 0.4);

    return std::make_shared<RF_GUI::RacerSFML >(entityLocation, standard, movement);
}

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

std::shared_ptr<RF_GUI::RoadSFML> Factory::createRoad(std::string &inputFile, const RF::location &loc) {

    RF::location newLoc(loc.first, loc.second - 12);
    RF::size standardSize(8, 6);
    RF::movementVector standardMovement(0, 0);

    return std::make_shared<RF_GUI::RoadSFML >(newLoc, standardSize, standardMovement, inputFile);

}
