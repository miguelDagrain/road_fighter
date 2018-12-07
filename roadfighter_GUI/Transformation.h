

#ifndef ROAD_FIGHTER_TRANSFORMATION_H
#define ROAD_FIGHTER_TRANSFORMATION_H

#include <Entity.h>


using exactLocation = std::pair<int, int>;

class Transformation
{
public:

    static Transformation& getInstance();

    Transformation(Transformation const&) = delete;
    void operator=(Transformation const&) = delete;

    exactLocation operator()(const location& loc, const int x, const int y);

private:

    Transformation() = default;
};


#endif //ROAD_FIGHTER_TRANSFORMATION_H
