//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../Headers/Game.h"
#include "../Headers/State/HQ_state.h"


Game::Game(int coins) : player{coins}{
    is_running = true;
}
void Game::run() {

    while (is_running) {
        game_state_context.get_current_state().run(player, game_state_context);
    }
}

void Game::quit() {
    Game::is_running = false;
}