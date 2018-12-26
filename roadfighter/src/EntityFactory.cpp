
#include "roadfighter/include/EntityFactory.h"





template<typename Tresult>
std::shared_ptr<Tresult> RF::Factory::createEntity()
{
    auto newPtr = new Tresult();

    return std::make_shared<Tresult >(*newPtr);
}

std::shared_ptr<RF::Bullet> RF::Factory::createBullet(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.1, 0.1);

    auto bullet = new RF::Bullet(entityLocation, standard, movement);

    return std::make_shared<RF::Bullet >(*bullet);
}

std::shared_ptr<RF::Fuelcar> RF::Factory::createFuelcar(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto fuelcar = new RF::Fuelcar(entityLocation, standard, movement);

    return std::make_shared<RF::Fuelcar >(*fuelcar);
}

std::shared_ptr<RF::Passingcar> RF::Factory::createPassingcar(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto passingcar = new RF::Passingcar(entityLocation, standard, movement);

    return std::make_shared<RF::Passingcar>(*passingcar);
}

std::shared_ptr<RF::Player> RF::Factory::createPlayer(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto player =new RF::Player(entityLocation, standard, movement);

    return std::make_shared<RF::Player>(*player);
}

std::shared_ptr<RF::Racer> RF::Factory::createRacer(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto racer = new RF::Racer(entityLocation, standard, movement);

    return std::make_shared<RF::Racer>(*racer);
}
