#include <iostream>
#include <limits>
#include "../../Headers/State/HQ_state.h"
#include "../../Headers/Models/Sector.h"

void HQ_state::run(Player &player, Game_state_context &context) {
    player.set_win_points(0);
    player.set_damage(0);

    std::cout << "Headquarters" << std::endl;

    context.clear_sectors();
    context.add_sectors();

    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            Sector* s = context.get_sector(x, y);
            if(s!= nullptr)
                std::cout << s->get_astr() << s->get_ont() << s->get_pla() << " ";
        }
        std::cout << std::endl;
    }
//
//    for(int i = 0; i < 25; i++){
//        Sector s;
//        s = context.get_sectors()[i];
//        std::cout << s.get_astr() << s.get_ont() << s.get_pla() << " ";
//        if(i!=0 && (i+1) % 5 == 0)
//            std::cout << std::endl;
//    }

    bool corect_input = false;
    int x = 0;
    int y = 0;

    cout << "input x: ";

    while(!corect_input){
        std::cin >> x;
        if(std::cin){
            if(-1 < x && x < 5)
                corect_input = true;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    corect_input = false;
    cout << "input y: ";
    while(!corect_input){
        std::cin >> y;
        if(std::cin){
            if(-1 < y && y < 5)
                corect_input = true;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    context.set_current_sector(x, y);
    context.get_current_sector().initialize();
    context.set_state(1);
}