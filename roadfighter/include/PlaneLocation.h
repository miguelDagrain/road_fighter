

#ifndef ROAD_FIGHTER_PLANELOCATION_H
#define ROAD_FIGHTER_PLANELOCATION_H

#include <utility>

namespace RF {

    struct PlaneLocation: public std::pair<double, double> {

        PlaneLocation();

        ~PlaneLocation();

        PlaneLocation(double one, double two);

        PlaneLocation &operator+=(const PlaneLocation& rhs);

        PlaneLocation &operator-=(const PlaneLocation& rhs);

        PlaneLocation operator*(double rhs) const;
    };

}

#endif //ROAD_FIGHTER_PLANELOCATION_H
