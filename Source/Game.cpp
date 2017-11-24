//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../Headers/Game.h"
#include "../Headers/State/Main_state.h"


Game::Game(int coins, Game_state game) : player{coins, &game}{
    is_running = true;
}
void Game::run() {

    auto *game = new Main_state();
    player.game_state = game;
    while (is_running) {


        player.game_state->run(&player);

    }
}

void Game::quit() {
    Game::is_running = false;
}