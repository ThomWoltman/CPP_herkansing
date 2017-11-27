//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_PLAYER_H
#define CPP_HERKANSING_PLAYER_H

class Game_state;

class Player {

    public:
        Player(int coins);
        void reset_dmg();
        void add_damage(int dmg);
    private:
        int coins;
        int damage;
};


#endif //CPP_HERKANSING_PLAYER_H
