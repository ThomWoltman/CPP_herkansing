//
// Created by administrator on 27-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_STATE_H
#define CPP_HERKANSING_SECTOR_STATE_H


#include "Game_state.h"

class Sector_state : public Game_state {
public:
    void run(Player &player, Game_state_context &context);
private:
};


#endif //CPP_HERKANSING_SECTOR_STATE_H
