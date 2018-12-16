
#include "roadfighter/include/PlaneLocation.h"


RF::PlaneLocation::PlaneLocation(double one, double two)
{
    this->first = one;
    this->second = two;
};

RF::PlaneLocation &RF::PlaneLocation::operator+=(const RF::PlaneLocation &rhs)
{
    this->first+=rhs.first;
    this->second+=rhs.second;

    return *this;
}

RF::PlaneLocation &RF::PlaneLocation::operator-=(const RF::PlaneLocation &rhs)
{
    this->first-=rhs.first;
    this->second-=rhs.second;

    return *this;
}
