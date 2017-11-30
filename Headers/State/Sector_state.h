//
// Created by administrator on 27-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_STATE_H
#define CPP_HERKANSING_SECTOR_STATE_H


#include "Game_state.h"
#include "../Models/Sector_item.h"


class Sector_state : public Game_state {
public:
    ~Sector_state() override;
    void run(Player &player, Game_state_context &context);
    void create_field();
    void draw_field();

private:
    Sector_item* field[10][10];
};


#endif //CPP_HERKANSING_SECTOR_STATE_H
