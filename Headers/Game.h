//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_GAME_H
#define CPP_HERKANSING_GAME_H


#include "Models/Player.h"
#include "State/Game_state.h"


class Game_state;

class Game {
public:
    Game(int coins, Game_state game);
    void run();
    void quit();

private:
    bool  is_running;
    Player player;
};


#endif //CPP_HERKANSING_GAME_H
