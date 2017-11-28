//
// Created by administrator on 27-11-17.
//

#include "../../Headers/State/Sector_state.h"

void Sector_state::run(Player &player, Game_state_context &context) {

    Sector sector = context.get_current_sector();
    std::cout << "Sector" << std::endl;
    std::cout << sector << std::endl;

    char i;
    std::cin >> i;
}