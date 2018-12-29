
#ifndef ROAD_FIGHTER_ROAD_H
#define ROAD_FIGHTER_ROAD_H

#include "roadfighter/include/Entity.h"

namespace RF {

   class Road: public Entity {

   public:
       Road();

       ~Road() override;

       Road(location &entityLocation, size &entitySize, movementVector &movement);

       void checkIfInWorld() override;

       void checkIfOnRoad() override;

       void checkIfCollided(const std::shared_ptr<Entity > &other) override;
   };
}

#endif //ROAD_FIGHTER_ROAD_H
