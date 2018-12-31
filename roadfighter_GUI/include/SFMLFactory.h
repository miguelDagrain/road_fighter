
#ifndef ROAD_FIGHTER_ENTITYFACTORY_H
#define ROAD_FIGHTER_ENTITYFACTORY_H

#include <memory>


#include "roadfighter/include/Entity.h"
#include "roadfighter/include/Bullet.h"
#include "roadfighter/include/Fuelcar.h"
#include "roadfighter/include/Passingcar.h"
#include "roadfighter/include/Player.h"
#include "roadfighter/include/Racer.h"
#include "roadfighter/include/Road.h"
#include "roadfighter/include/World.h"

#include "roadfighter_GUI/include/BulletSFML.h"
#include "roadfighter_GUI/include/FuelcarSFML.h"
#include "roadfighter_GUI/include/PassingcarSFML.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "roadfighter_GUI/include/RacerSFML.h"
#include "roadfighter_GUI/include/RoadSFML.h"
#include "FinishSFML.h"


class Factory {
public:
    Factory() = default;

    virtual ~Factory() = default;

    template <typename Tresult>
    std::shared_ptr<Tresult > createEntity();

    std::shared_ptr<RF_GUI::BulletSFML > createBullet(RF::location &entityLocation, RF::movementVector &movement);

    std::shared_ptr<RF_GUI::FuelcarSFML > createFuelcar(RF::location &entityLocation);

    std::shared_ptr<RF_GUI::PassingcarSFML > createPassingcar(RF::location &entityLocation);

    std::shared_ptr<RF_GUI::PlayerSFML > createPlayer(RF::location &entityLocation, RF::movementVector &movement);

    std::shared_ptr<RF_GUI::RacerSFML > createRacer(RF::location &entityLocation, RF::movementVector &movement);

    std::shared_ptr<RF_GUI::RoadSFML > createRoad(std::string &inputFile, int pos);

    std::shared_ptr<RF_GUI::RoadSFML > createRoad(std::string &inputFile, const RF::location &loc);

    std::shared_ptr<RF_GUI::FinishSFML > createFinish(std::string &inputFile, const RF::location &loc);
};

#endif //ROAD_FIGHTER_ENTITYFACTORY_H