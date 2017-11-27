//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_MAIN_STATE_H
#define CPP_HERKANSING_MAIN_STATE_H


#include "Game_state.h"

class Main_state : public Game_state {
public:

void run(Player &player);

void show() {}

void handle_input(Player &player) {}
};


#endif //CPP_HERKANSING_MAIN_STATE_H
