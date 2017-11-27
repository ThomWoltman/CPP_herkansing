//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../../Headers/State/Game_state.h"
Game_state::Game_state() {

}

void Game_state::show(){
    std::cout << "Hello I am state this works" << std::endl;
}
void Game_state::handle_input(Player &player){

}
void Game_state::run(Player &player){
    std::cout << "Hello I am state this works" << std::endl;

}

void Game_state::check_state() {}


