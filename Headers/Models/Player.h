//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_PLAYER_H
#define CPP_HERKANSING_PLAYER_H

class Game_state;

class Player {

public:
    Player();
    void repair();
    void add_damage(int dmg);
    void add_win_point();
    void remove_win_point();
    const int get_win_point() const;
    const int get_damage() const;
    void set_win_points(const int points);
    void set_damage(const int dmg);
private:
    int damage = 0;
    int win_points = 0;
};


#endif //CPP_HERKANSING_PLAYER_H
