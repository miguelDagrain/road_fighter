//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_PLANELOCATION_H
#define ROAD_FIGHTER_PLANELOCATION_H

#include <utility>

namespace RF {

    struct PlaneLocation: public std::pair<double, double> {

        PlaneLocation() = default;

        PlaneLocation(double one, double two);

        PlaneLocation &operator+=(const PlaneLocation& rhs);

        PlaneLocation &operator-=(const PlaneLocation& rhs);
    };

}

#endif //ROAD_FIGHTER_PLANELOCATION_H
