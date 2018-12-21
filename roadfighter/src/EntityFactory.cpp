
#include <include/EntityFactory.h>

#include "roadfighter/include/EntityFactory.h"





template<typename Tresult> template<typename... Targs>
std::shared_ptr<Tresult> RF::Factory::BaseFactory<Tresult>::createEntity(Targs... args)
{
    return std::make_shared<Tresult >(new Tresult());
}

std::shared_ptr<RF::Bullet> RF::Factory::BulletFactory::createEntity()
{
    return std::make_shared<RF::Bullet >(new RF::Bullet());
}

std::shared_ptr<RF::Bullet> RF::Factory::BulletFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.1, 0.1);

    return std::make_shared<RF::Bullet >(new RF::Bullet(entityLocation, standard, movement));
}

std::shared_ptr<RF::Fuelcar> RF::Factory::FuelcarFactory::createEntity()
{
    return std::make_shared<RF::Fuelcar>(new RF::Fuelcar());
}

std::shared_ptr<RF::Fuelcar> RF::Factory::FuelcarFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    return std::make_shared<RF::Fuelcar >(new RF::Fuelcar(entityLocation, standard, movement));
}

std::shared_ptr<RF::Passingcar> RF::Factory::PassingcarFactory::createEntity()
{
    return std::make_shared<RF::Passingcar>(new RF::Passingcar());
}

std::shared_ptr<RF::Passingcar> RF::Factory::PassingcarFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    return std::make_shared<RF::Passingcar>(new RF::Passingcar(entityLocation, standard, movement));
}

std::shared_ptr<RF::Player> RF::Factory::PlayerFactory::createEntity()
{
    return std::make_shared<RF::Player>(new RF::Player());
}

std::shared_ptr<RF::Player> RF::Factory::PlayerFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    return std::make_shared<RF::Player>(new RF::Player(entityLocation, standard, movement));
}

std::shared_ptr<RF::Racer> RF::Factory::RacerFactory::createEntity()
{
    return std::make_shared<RF::Racer>(new RF::Racer());
}

std::shared_ptr<RF::Racer> RF::Factory::RacerFactory::createEntity(RF::location &entityLocation, RF::movementVector &movement)
{
    size standard(0.4, 0.4);

    return std::make_shared<RF::Racer>(new RF::Racer(entityLocation, standard, movement));
}

std::shared_ptr<RF::World> RF::Factory::WorldFactory::createEntity()
{
    return std::make_shared<RF::World>(new World());
}
