#include <iostream>
#include "../../Headers/State/HQ_state.h"
#include "../../Headers/Models/Sector.h"

void HQ_state::run(Player &player, Game_state_context &context) {

    //sectors.clear();
    std::cout << "Headquarters" << std::endl;
    for(int i = 0; i < 25; i++){
        Sector sector;
        context.add_sector(sector);
    }

    for(int i = 0; i < context.get_sectors().length(); i++){
        std::cout << context.get_sectors()[i] << " ";
        if((i+1)%5 == 0)
            std::cout << std::endl;
    }

    bool corect_input = false;
    int input = 0;

    while(!corect_input){
        std::cin >> input;
        if(-1 < input && input < 25)
            corect_input = true;
    }

    context.set_current_sector(input);
    context.set_state(1);
}