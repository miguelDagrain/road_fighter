
#include "roadfighter/include/EntityFactory.h"





template<typename Tresult> template<typename... Targs>
std::shared_ptr<Tresult> RF::Factory::BaseFactory<Tresult>::createEntity(Targs... args)
{
    auto newPtr = new Tresult();

    return std::make_shared<Tresult >(*newPtr);
}

std::shared_ptr<RF::Bullet> RF::Factory::BulletFactory::createEntity()
{
    auto bullet = new RF::Bullet();

    return std::make_shared<RF::Bullet >(*bullet);
}

std::shared_ptr<RF::Bullet> RF::Factory::BulletFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.1, 0.1);

    auto bullet = new RF::Bullet(entityLocation, standard, movement);

    return std::make_shared<RF::Bullet >(*bullet);
}

std::shared_ptr<RF::Fuelcar> RF::Factory::FuelcarFactory::createEntity()
{
    auto fuelcar = new RF::Fuelcar();

    return std::make_shared<RF::Fuelcar>(*fuelcar);
}

std::shared_ptr<RF::Fuelcar> RF::Factory::FuelcarFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto fuelcar = new RF::Fuelcar(entityLocation, standard, movement);

    return std::make_shared<RF::Fuelcar >(*fuelcar);
}

std::shared_ptr<RF::Passingcar> RF::Factory::PassingcarFactory::createEntity()
{
    auto passingcar = new RF::Passingcar();

    return std::make_shared<RF::Passingcar>(*passingcar);
}

std::shared_ptr<RF::Passingcar> RF::Factory::PassingcarFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto passingcar = new RF::Passingcar(entityLocation, standard, movement);

    return std::make_shared<RF::Passingcar>(*passingcar);
}

std::shared_ptr<RF::Player> RF::Factory::PlayerFactory::createEntity()
{
    auto player = new RF::Player();

    return std::make_shared<RF::Player>(*player);
}

std::shared_ptr<RF::Player> RF::Factory::PlayerFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto player =new RF::Player(entityLocation, standard, movement);

    return std::make_shared<RF::Player>(*player);
}

std::shared_ptr<RF::Racer> RF::Factory::RacerFactory::createEntity()
{
    auto racer = new RF::Racer();

    return std::make_shared<RF::Racer>(*racer);
}

std::shared_ptr<RF::Racer> RF::Factory::RacerFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    auto racer = new RF::Racer(entityLocation, standard, movement);

    return std::make_shared<RF::Racer>(*racer);
}

std::shared_ptr<RF::World> RF::Factory::WorldFactory::createEntity()
{
    auto world = new World();

    return std::make_shared<RF::World>(*world);
}
