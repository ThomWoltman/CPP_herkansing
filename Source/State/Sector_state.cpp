//
// Created by administrator on 27-11-17.
//

#include "../../Headers/State/Sector_state.h"
#include "../../Headers/Models/Sector_item.h"
#include "../../Headers/Models/Sector_empty.h"
#include "../../Headers/Libs/String.h"
#include "../../Headers/Libs/Random.h"
#include "../../Headers/Models/Sector_planeet.h"
#include "../../Headers/Models/Sector_asteroide.h"
#include "../../Headers/Models/Sector_ontmoeting.h"
#include "../../Headers/Models/Sector_ship.h"
#include "../../Headers/Libs/CSV_reader.h"

Sector_state::Sector_state() {
}

Sector_state::~Sector_state() {

}
void Sector_state::pick_up_package(Game_state_context & game_context) {

    CSV_reader reader;
    String path("/home/administrator/Documents/CPP_herkansing/Data/Pakketjes.csv"); // glenn local path
    //String path("/home/administrator/CLionProjects/CPP_herkansing/Data/Pakketjes.csv") // thom local path
    auto b = reader.get_data(path);

    for(int i = 0; i < b.length() ;i++){
        std::cout << i << ". ";
        std::cout << b[i] << std::endl;
    }
    std::cout << "which package do you want to pick up?" << std::endl;

    String input;
    cin >> input;
    int number = -1;
    try {
      number = std::stoi(input.get_string());
    } catch (std::exception const &e) {
        std::cout << "No number entered" << std::endl;

    }
    if(number > -1 && number < b.length()){
        Package p = b[number];
        game_context.set_current_package(p);
    }else{
        std::cout << "No correct number entered" << std::endl;

    }


}

void Sector_state::run(Player &player, Game_state_context &context) {
    std::cout << "Sector" << std::endl;
    std::cout << "x = " << context.get_current_sector_x() << std::endl;
    std::cout << "y = " << context.get_current_sector_y() << std::endl;
    std::cout << context.get_current_sector() << std::endl;
    std::cout << context.get_current_package() << std::endl;

    std::cout << "[w][a][s][d][o][quit]: ";
    String str;
    std::cin >> str;

    if(str == "d"){
        if(!context.get_current_sector().move_right()){
            context.next_sector(1,0);
        }
    }
    else if(str == "a"){
        if(!context.get_current_sector().move_left()){
            context.next_sector(-1,0);
        }
    }
    else if(str == "w"){
        if(!context.get_current_sector().move_up()){
            context.next_sector(0,-1);
        }
    }
    else if(str == "s"){
        if(!context.get_current_sector().move_down()){
            context.next_sector(0,1);
        }
    }else if(str == "o"){
        if( context.get_current_sector().next_planet()){
        pick_up_package(context);
        }

    }
    else if(str == "quit"){
        context.game_over();
    }
    context.get_current_sector().move_meetings();
}