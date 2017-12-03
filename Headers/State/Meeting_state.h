//
// Created by administrator on 3-12-17.
//

#ifndef CPP_HERKANSING_MEETING_STATE_H
#define CPP_HERKANSING_MEETING_STATE_H

#include "Game_state.h"

class Meeting_state : public Game_state {
public:
    Meeting_state();
    ~Meeting_state() override;
    void run(Player &player, Game_state_context &context);
private:
};

#endif //CPP_HERKANSING_MEETING_STATE_H
