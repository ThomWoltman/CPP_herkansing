//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_GAME_H
#define CPP_HERKANSING_GAME_H


#include "Models/Player.h"
#include "State/Game_state.h"
#include "State/Game_state_context.h"


class Game_state;

class Game {
public:
    Game(int coins);
    void run();
    void quit();

private:
    bool  is_running;
    Player player;
    Game_state_context game_state_context;
};


#endif //CPP_HERKANSING_GAME_H
