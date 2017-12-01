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

Sector_state::Sector_state() {

}

Sector_state::~Sector_state() {

}

void Sector_state::run(Player &player, Game_state_context &context) {
    std::cout << "Sector" << std::endl;
    std::cout << context.get_current_sector() << std::endl;

    String str;

    std::cin >> str;

    if(str == "d"){
        context.get_current_sector().move_right();
    }
    else if(str == "a"){
        context.get_current_sector().move_left();
    }
    else if(str == "w"){
        context.get_current_sector().move_up();
    }
    else if(str == "s"){
        context.get_current_sector().move_down();
    }
    else if(str == "quit"){
        context.game_over();
    }
}