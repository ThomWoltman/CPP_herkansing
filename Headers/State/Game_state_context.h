//
// Created by administrator on 26-11-17.
//

#ifndef CPP_HERKANSING_GAME_STATE_CONTEXT_H
#define CPP_HERKANSING_GAME_STATE_CONTEXT_H


#include "Game_state.h"
#include "../Libs/Array.h"

class Game_state_context {
public:
    Game_state_context();
    ~Game_state_context();
    void set_state(int index);
    Game_state& get_current_state();
private:
    Array<Game_state*> states;
    int currentstate;
};


#endif //CPP_HERKANSING_GAME_STATE_CONTEXT_H
