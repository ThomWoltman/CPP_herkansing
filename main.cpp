#include <iostream>
#include "Headers/Game.h"
#include "Headers/Libs/String.h"
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
        std::cout << b[i] << std::endl;
    }


    String input;
    String compare{"hello"};

    std::cin >> input;

    std::cout << input << std::endl;

    if (input == compare)
        std::cout << "true" << std::endl;
    else {
        std::cout << "false" << std::endl;
    }

    return 0;
}