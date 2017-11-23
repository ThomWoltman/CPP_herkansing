//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_PLAYER_H
#define CPP_HERKANSING_PLAYER_H

class Game_state;

class Player {

    public:
        Player(int coins, Game_state *g);

        Game_state* game_state;


    private:
        int coins;


};


#endif //CPP_HERKANSING_PLAYER_H
