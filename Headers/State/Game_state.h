//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_GAME_STATE_H
#define CPP_HERKANSING_GAME_STATE_H


#include "../Models/Player.h"
#include "Game_state_context.h"

class Player;
using namespace std;
class Game_state {
public:
    Game_state();
    virtual ~Game_state(){};

    virtual void run(Player &player, Game_state_context &context);
    virtual void check_state();
    virtual void show();
    virtual void handle_input(Player &player);
private:

};

#endif //CPP_HERKANSING_GAME_STATE_H
