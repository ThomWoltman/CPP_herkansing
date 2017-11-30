//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../Headers/Game.h"
#include "../Headers/State/HQ_state.h"
#include "../Headers/Libs/String.h"


Game::Game(int coins) : player{coins}{
    is_running = true;
}
void Game::run() {

    while (is_running) {
        game_state_context.get_current_state().run(player, game_state_context);
        String input;
        String compare{"quit"};

        std::cin >> input;

        std::cout << input << std::endl;

        if (input == compare){
            std::cout << "true" << std::endl;
            is_running = false;
        }

        else {
            std::cout << "false" << std::endl;
        }
    }


}

void Game::quit() {
    Game::is_running = false;
}