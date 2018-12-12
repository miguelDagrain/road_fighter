#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include <memory>

#include <PlaneLocation.h>
#include <RoadfighterError.h>

namespace RF {

    using location = PlaneLocation;
    using size = PlaneLocation;
    using movementVector = PlaneLocation;

    class Entity {

    public:

        Entity() = default;

        Entity(location& entityLocation, size& entitySize);

        Entity(location& entityLocation, size& entitySize, movementVector& movement);

        virtual void addObject(std::shared_ptr<Entity > newbornObject);

        virtual void removeObject(std::shared_ptr<Entity > deadObject);


        virtual const location &getLocation() const;

        virtual const size &getSize() const;

        virtual const movementVector &getMovement() const;

        virtual void setMovement(movementVector &newVelocity);

        virtual void attackAction(std::shared_ptr<Entity > world);


        virtual void update();

        //functie om de wereld rond het centrum te houden, de 'wereld' beweegt dus in de richting van de correctionVector.
        virtual void correctPosition(PlaneLocation& correctionVector);

    private:
        location entityLocation;
        size entitySize;

        movementVector movement;

    };


}


#endif //ROAD_FIGHTER_ENTITY_H
