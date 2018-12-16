//
// Created by miguel on 12.12.18.
//

#include "roadfighter/include/RoadfighterError.h"

RF::RoadfighterError::RoadfighterError(const char *error_msg): error_msg(error_msg) {

}

const char *RF::RoadfighterError::what() const noexcept {
    std::string str(error_msg);
    return ("Roadfighter error:\t" + str).c_str();
}
