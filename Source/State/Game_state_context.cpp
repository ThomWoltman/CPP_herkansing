//
// Created by administrator on 26-11-17.
//

#include "../../Headers/State/Game_state_context.h"
#include "../../Headers/State/Main_state.h"

Game_state_context::Game_state_context() : states{Array<Game_state*>{1}} {
    currentstate = 0;
    states.push_back(new Main_state);
}

Game_state_context::~Game_state_context() {
    for(int i = 0; i < states.length(); i++){
        delete states[i];
    }
}

Game_state& Game_state_context::get_current_state() {
    return *states[currentstate];
}

void Game_state_context::set_state(const int index) {
    currentstate = index;
}