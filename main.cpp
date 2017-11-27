#include <iostream>
#include "Headers/Libs/Random.h"
#include "Headers/Game.h"
#include "Headers/State/Main_state.h"
#include "Headers/Libs/String.h"
#include "Headers/Libs/Vector.h"
#include "Headers/Models/Package.h"
#include "Headers/Libs/CSV_reader.h"

using namespace std;
int main() {

    Game game1{1000};
    game1.run();

    CSV_reader reader;
    String path("/home/administrator/CLionProjects/CPP_herkansing/Data/Pakketjes.csv");
    auto b = reader.get_data(path);

    for(int i = 0; i < b.length() ;i++){
        std::cout << i << ". ";
        b[i].bestemming.print();
        std::cout << " - ";
        b[i].inhoud.print();
        std::cout << std::endl;
    }
    String input;

    std::cin >> input;

    std::cout << input << std::endl;

    return 0;
}