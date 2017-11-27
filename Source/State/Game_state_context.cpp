//
// Created by administrator on 26-11-17.
//

#include "../../Headers/State/Game_state_context.h"
#include "../../Headers/State/HQ_state.h"
#include "../../Headers/State/Sector_state.h"

Game_state_context::Game_state_context() : states{Vector<Game_state*>{1}} {
    currentstate = 0;
    states.push_back(new HQ_state);
    states.push_back(new Sector_state);
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

Vector<Sector>& Game_state_context::get_sectors() {
    return sectors;
}

void Game_state_context::add_sector(const Sector &sector) {
    sectors.push_back(sector);
}

Sector& Game_state_context::get_current_sector() {
    return sectors[currentsector];
}

void Game_state_context::set_current_sector(int index) {
    currentsector = index;
}