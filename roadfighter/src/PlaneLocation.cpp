
#include "roadfighter/include/PlaneLocation.h"

/**
 * @brief basis constructor van een PlaneLocation.
 */
RF::PlaneLocation::PlaneLocation() = default;

/**
 * @brief destructor van een PlaneLocation.
 */
RF::PlaneLocation::~PlaneLocation() = default;

/**
 * @brief constructor van een PlaneLocation met 2 doubles.
 *
 * @param one eerste van de twee doubles.
 * @param two tweede van de twee doubles.
 */
RF::PlaneLocation::PlaneLocation(double one, double two)
{
    this->first = one;
    this->second = two;
};

/**
 * @brief operator overload van += voor een PlaneLocation.
 *
 * @param rhs de PlaneLocation waarvan de waarde bij de waarde van deze PlaneLocation wordt bijgeteld.
 * @return een referentie naar dit object.
 */
RF::PlaneLocation &RF::PlaneLocation::operator+=(const RF::PlaneLocation &rhs)
{
    this->first+=rhs.first;
    this->second+=rhs.second;

    return *this;
}

/**
 * @brief operator overload van -= voor een PlaneLocation.
 *
 * @param rhs de PlaneLocation waarvan de waarde van de waarde van deze PlaneLocation wordt afgetrokken.
 * @return referentie naar dit object.
 */
RF::PlaneLocation &RF::PlaneLocation::operator-=(const RF::PlaneLocation &rhs)
{
    this->first-=rhs.first;
    this->second-=rhs.second;

    return *this;
}

/**
 * @brief operator overload van * voor een PlaneLocation.
 *
 * @param rhs de PlaneLocation die we met deze PlaneLocation vermenigvuldigen.
 * @return een nieuw gemaakte PlaneLocation van het object.
 */
RF::PlaneLocation RF::PlaneLocation::operator*(const double rhs) const {
    PlaneLocation newLoc;

    newLoc.first = this->first * rhs;
    newLoc.second = this->second * rhs;

    return newLoc;
}
