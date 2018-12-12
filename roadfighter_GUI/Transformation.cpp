

#include <stdexcept>
#include "Transformation.h"

exactLocation Transformation::operator()(const RF::location &loc, const int x, const int y) {
    if(loc.first > 3 or loc.first < -3 or loc.second > 4 or loc.second < -4){
        throw std::runtime_error("the given coordinates aren't within the correct range [-4, 4]x[-3, 3]");
    }

    //breng de coordinaten in het juiste kwadrant
    double xValue = loc.first + 3;
    double yValue = loc.second + 4;

    exactLocation transformed;

    //herschaal de locatie van de coordinaten
    transformed.first = (xValue/6)*x;
    transformed.second = (yValue/8)*y;

    return transformed;
}
