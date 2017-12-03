#include <iostream>
#include "Headers/Game.h"
#include "Headers/Libs/String.h"
#include "Headers/Models/Package.h"
#include "Headers/Libs/CSV_reader.h"
#include "Headers/Libs/CSV_reader_meeting.h"

using namespace std;
int main() {

    //String* str = new String{"bla"};

    Game game1{1000};
    game1.run();
//
//    CSV_reader_meeting reader;
//    String s;
//    s.operator=("/home/administrator/Documents/CPP_herkansing/Data/Ontmoetingen.csv");
//    auto b = reader.get_data(s);
//    CSV_reader reader;
//    String path("/home/administrator/CLionProjects/CPP_herkansing/Data/Pakketjes.csv");
//    auto b = reader.get_data(path);
//
//    for(int i = 0; i < b.length() ;i++){
//        std::cout << i << ". ";
//        std::cout << b[i] << std::endl;
//    }

    return 0;
}