#include <iostream>
#include "Headers/Libs/Random.h"
#include "Headers/Game.h"
#include "Headers/State/Main_state.h"
#include "Headers/Libs/String.h"
#include "Headers/Libs/Array.h"
#include "Headers/Models/Pakage.h"
using namespace std;
int main() {
    Random random;

    std::cout << "Hello, World!" << random.get_random(0,20)<< std::endl;

//    Game game{1000, Main_state()};
//    game.run();
    Array<Pakage> array{10};

    array.push_back(Pakage{"inhoud "," locatie"});

   array[0].bestemming;



    return 0;
}