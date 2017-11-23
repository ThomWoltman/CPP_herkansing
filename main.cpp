#include <iostream>
#include "Headers/Libs/Random.h"
#include "Headers/Game.h"
#include "Headers/State/Main_state.h"

int main() {
    Random random;

    std::cout << "Hello, World!" << random.get_random(0,20)<< std::endl;

    Game game{1000, Main_state()};
    game.run();


    return 0;
}