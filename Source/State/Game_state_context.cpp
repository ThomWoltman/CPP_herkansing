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
        auto state = states[i];
        delete state;
    }
}

void Game_state_context::clear_sectors() {

}

Game_state& Game_state_context::get_current_state() {
    return *states[currentstate];
}

void Game_state_context::set_state(const int index) {
    currentstate = index;
}

Sector* Game_state_context::get_sectors() {
    return *sectors;
}

void Game_state_context::add_sectors() {
    for(int y = 0; y < 5; ++y){
        for(int x = 0; x < 5; ++x){
            sectors[y][x] = Sector();
        }
    }
}

Sector& Game_state_context::get_current_sector() {
    return sectors[currentsector_x][currentsector_y];
}

void Game_state_context::set_current_sector(const int x, const int y) {
    currentsector_y = y;
    currentsector_x = x;
}

void Game_state_context::next_sector(int x, int y) {
    int next_x = get_current_sector().get_player_x() - 9*x;
    int next_y = get_current_sector().get_player_y() - 9*y;

    currentsector_x += x;
    currentsector_y += y;

    if(currentsector_x < 0 || currentsector_x > 4 || currentsector_y < 0 || currentsector_y > 4)
        set_state(0);
    else{
        get_current_sector().initialize(next_x,next_y);
    }
}