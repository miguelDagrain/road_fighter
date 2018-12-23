//
// Created by miguel on 12.12.18.
//

#ifndef ROAD_FIGHTER_ROADFIGHTERERROR_H
#define ROAD_FIGHTER_ROADFIGHTERERROR_H


#include <exception>
#include <stdexcept>

namespace RF {

    class RoadfighterError : public std::exception {

    public:
        explicit RoadfighterError(const char* error_msg);

        ~RoadfighterError() override = default;

        const char* what() const noexcept final;

    private:

        const char* error_msg;
    };
}

#endif //ROAD_FIGHTER_ROADFIGHTERERROR_H
