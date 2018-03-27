//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_MAIN_STATE_H
#define CPP_HERKANSING_MAIN_STATE_H


#include "Game_state.h"
#include "../Models/Sector.h"
#include "../Libs/Vector.h"

class HQ_state : public Game_state {
public:

void run(Player &player, Game_state_context &context);

void show() {}

void handle_input(Player &player) {}

private:
    //Vector<Sector> sectors;
};

#endif //CPP_HERKANSING_MAIN_STATE_H
