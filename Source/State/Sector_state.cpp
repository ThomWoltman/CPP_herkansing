//
// Created by administrator on 27-11-17.
//

#include "../../Headers/State/Sector_state.h"

void Sector_state::run(Player &player, Game_state_context &context) {
    std::cout << "Sector" << std::endl;
    std::cout << context.get_current_sector() << std::endl;

    char i;
    std::cin >> i;
}