

#include "roadfighter/include/RoadfighterError.h"

/**
 * @brief constructor voor een error die wordt geworpen als er een logische fout wordt gemaakt.
 *
 * @param error_msg de message die wordt geworpen.
 */
RF::RoadfighterError::RoadfighterError(const char *error_msg): error_msg(error_msg)
{
}

/**
 * @brief de what functie die wordt gebruikt om weer te geven wat de fout is.
 *
 * @return een string die de fout uitlegt.
 */
const char *RF::RoadfighterError::what() const noexcept {
    std::string str(error_msg);
    return ("Roadfighter error:\t" + str).c_str();
}
