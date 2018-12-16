

#include <stdexcept>

#include "roadfighter_GUI/include/Transformation.h"

exactLocation RF_GUI::Transformation::operator()(const RF::location &loc, const int x, const int y) {
    if(loc.first > 4 or loc.first < -4 or loc.second > 3 or loc.second < -3){
        throw std::runtime_error("the given coordinates aren't within the correct range [-4, 4]x[-3, 3]");
    }

    //breng de coordinaten in het juiste kwadrant
    double xValue = loc.first + 4;
    double yValue = loc.second + 3;

    exactLocation transformed;

    //herschaal de locatie van de coordinaten
    transformed.first =  (xValue/8.0)*x;
    transformed.second = (yValue/6.0)*y;

    return transformed;
}
