//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../Headers/Game.h"
#include "../Headers/State/Main_state.h"


Game::Game(int coins) : player{coins}{
    is_running = true;
}
void Game::run() {

    while (is_running) {
        game_state_context.get_current_state().run(player);
        is_running = false;
    }
}

void Game::quit() {
    Game::is_running = false;
}