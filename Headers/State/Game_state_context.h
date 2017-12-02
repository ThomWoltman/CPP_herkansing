//
// Created by administrator on 26-11-17.
//

#ifndef CPP_HERKANSING_GAME_STATE_CONTEXT_H
#define CPP_HERKANSING_GAME_STATE_CONTEXT_H

#include "../Libs/Vector.h"
#include "../Models/Sector.h"
#include "../Models/Package.h"

class Game_state;
class Game_state_context {
public:
    Game_state_context();
    ~Game_state_context();
    void set_state(int index);
    Game_state& get_current_state();
    //Vector<Sector>& get_sectors();
    Sector* get_sectors();
    //void add_sector(const Sector &sector);
    void add_sectors();
    Sector& get_current_sector();
    void set_current_sector(int x, int y);
    Package& get_current_package();
    void set_current_package(Package);

    void game_over(){
        winning = false;
    }
    bool is_winning() const{
        return winning;
    }
    void next_sector(int x, int y);
    void clear_sectors();
    const int get_current_sector_x() const {return currentsector_x;}
    const int get_current_sector_y() const {return currentsector_y;}
private:
    Vector<Game_state*> states;
    int currentstate;
    Sector sectors[5][5];
    int currentsector_x = -1;
    int currentsector_y = -1;
    bool winning = true;
    Package current_package = Package();
};


#endif //CPP_HERKANSING_GAME_STATE_CONTEXT_H
