
#include "roadfighter/include/EntityFactory.h"


std::shared_ptr<RF::Bullet > RF::Factory::BulletFactory::createEntity()
{
    return nullptr;
}

std::shared_ptr<RF::Bullet > RF::Factory::BulletFactory::createEntity(RF::location &entityLocation)
{
    RF::size standard(0.1, 0.1);
    return nullptr;
//    return std::make_shared<Bullet >(RF::Bullet(entityLocation, standard));
}

std::shared_ptr<RF::Fuelcar > RF::Factory::FuelcarFactory::createEntity() {
    return nullptr;
}

std::shared_ptr<RF::Passingcar > RF::Factory::PassingcarFactory::createEntity() {
    return nullptr;
}

std::shared_ptr<RF::Player > RF::Factory::PlayerFactory::createEntity() {
    return nullptr;
}

std::shared_ptr<RF::Racer > RF::Factory::RacerFactory::createEntity() {
    return nullptr;
}

std::shared_ptr<RF::World > RF::Factory::WorldFactory::createEntity() {
    return nullptr;
}
