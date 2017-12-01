//
// Created by administrator on 26-11-17.
//

#ifndef CPP_HERKANSING_GAME_STATE_CONTEXT_H
#define CPP_HERKANSING_GAME_STATE_CONTEXT_H

#include "../Libs/Vector.h"
#include "../Models/Sector.h"

class Game_state;
class Game_state_context {
public:
    Game_state_context();
    ~Game_state_context();
    void set_state(int index);
    Game_state& get_current_state();
    Vector<Sector>& get_sectors();
    void add_sector(const Sector &sector);
    Sector& get_current_sector();
    void set_current_sector(int index);
    void game_over(){
        winning = false;
    }
    bool is_winning() const{
        return winning;
    }
private:
    Vector<Game_state*> states;
    int currentstate;
    Vector<Sector> sectors;
    int currentsector;
    bool winning = true;
};


#endif //CPP_HERKANSING_GAME_STATE_CONTEXT_H
