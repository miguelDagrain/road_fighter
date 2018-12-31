
#include <iostream>

#include "include/SFMLFactory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "roadfighter_GUI/include/Interface.h"







int main(int argc, char* argv[]) {

    Interface runner(10);

    runner.runGame(argv[1], argv[2]);

    return 0;
}