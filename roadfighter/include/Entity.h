#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include <memory>
#include <vector>

#include "roadfighter/include/PlaneLocation.h"
#include "roadfighter/include/RoadfighterError.h"

namespace RF {

    using location = PlaneLocation;
    using size = PlaneLocation;
    using movementVector = PlaneLocation;

    class Entity {


    public:

        Entity();

        Entity(location& entityLocation, size& entitySize, movementVector& movement);

        virtual ~Entity();

        virtual void addObject(std::shared_ptr<Entity > newbornObject);

        virtual void removeObject(std::shared_ptr<Entity > deadObject);


        virtual const location &getLocation() const;

        virtual const size &getSize() const;

        virtual const movementVector &getMovement() const;

        virtual bool hasCrashed() const;

        virtual void accelerate(movementVector &acceleration);


        virtual void attackAction(Entity &world);

        virtual void checkIfInWorld();

        virtual void checkIfOnRoad();

        virtual void checkIfCollided(const std::shared_ptr<Entity > &other);

        virtual void update();

        //functie om de wereld rond het centrum te houden, de 'wereld' beweegt dus in de richting van de correctionVector.
        virtual void correctPosition(PlaneLocation correctionVector);

        virtual void draw();

    protected:

        location entityLocation;
        //hoek over dewelke de entiteit gedraaid moet worden (per draw)
        int rotation;

        size entitySize;

        movementVector movement;

        bool crashed;

        int specialActionDuration;
    };


}


#endif //ROAD_FIGHTER_ENTITY_H
