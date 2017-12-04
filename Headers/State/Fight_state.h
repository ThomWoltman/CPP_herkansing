//
// Created by administrator on 3-12-17.
//

#ifndef CPP_HERKANSING_FIGHT_STATE_H
#define CPP_HERKANSING_FIGHT_STATE_H


#include "Game_state.h"

class Fight_state : public Game_state {
public:
    Fight_state();

    ~Fight_state() override;
    void run(Player &player, Game_state_context &context);
private:
    void handle_input(Player &player, Game_state_context &context);
    int round = 1;
    int hits = 0;

};


#endif //CPP_HERKANSING_FIGHT_STATE_H
