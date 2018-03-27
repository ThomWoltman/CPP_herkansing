//
// Created by administrator on 26-11-17.
//

#include "../../Headers/State/Game_state_context.h"
#include "../../Headers/State/HQ_state.h"
#include "../../Headers/State/Sector_state.h"
#include "../../Headers/State/Meeting_state.h"
#include "../../Headers/State/Fight_state.h"

Game_state_context::Game_state_context() : states{Vector<Game_state*>{3}} {
    currentstate = 0;
    states.push_back(new HQ_state);
    states.push_back(new Sector_state);
    states.push_back(new Meeting_state);
    states.push_back(new Fight_state);
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
    return sectors[currentsector_y][currentsector_x];
}

Sector* Game_state_context::get_sector(const int x, const int y) {
    if(x >= 0 && x < 5 && y >= 0 && y < 5){
        return &sectors[y][x];
    }
    return nullptr;
}

void Game_state_context::set_current_sector(const int x, const int y) {
    currentsector_y = y;
    currentsector_x = x;
}

void Game_state_context::next_sector(int x, int y) {
    int next_x = get_current_sector().get_player_x() - 9*x;
    int next_y = get_current_sector().get_player_y() - 9*y;

    if(currentsector_x + x < 0 || currentsector_x + x > 4 || currentsector_y + y < 0 || currentsector_y + y > 4){
        set_state(0);
    }
    else{
        currentsector_x += x;
        currentsector_y += y;
        get_current_sector().initialize(next_x,next_y);
    }
}

Package& Game_state_context::get_current_package() {
    return current_package;
}
void Game_state_context::set_current_package(Package package) {
    current_package = package;
}
Meeting& Game_state_context::get_current_meeting() {
    return current_meeting;
}
void Game_state_context::set_current_meeting(Meeting meeting) {
    current_meeting = meeting;
}

void Game_state_context::set_damage(const int min, const int max) {
    min_damage = min;
    max_damage = max;
}