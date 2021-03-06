//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../Headers/Game.h"
#include "../Headers/Libs/CSV_reader_meeting.h"


Game::Game(){
    is_running = true;
}
void Game::run() {

    while (game_state_context.is_winning()) {
        game_state_context.get_current_state().run(player, game_state_context);
        std::cout << std::endl << "---------------------------------" << std::endl;
    }
}

void Game::quit() {
    Game::is_running = false;
}