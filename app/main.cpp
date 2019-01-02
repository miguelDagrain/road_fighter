
#include <iostream>

#include "Factory.h"
#include "roadfighter_GUI/include/PlayerSFML.h"
#include "Interface.h"


int main(int argc, char* argv[]) {

    Interface runner(100);

    runner.runGame(argv[1], argv[2]);

    return 0;
}