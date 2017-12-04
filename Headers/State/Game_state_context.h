//
// Created by administrator on 26-11-17.
//

#ifndef CPP_HERKANSING_GAME_STATE_CONTEXT_H
#define CPP_HERKANSING_GAME_STATE_CONTEXT_H

#include "../Libs/Vector.h"
#include "../Models/Sector.h"
#include "../Models/Package.h"
#include "../Models/Meeting.h"

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
    Sector* get_sector(const int x, const int y);
    void set_current_sector(int x, int y);
    Package& get_current_package();
    void set_current_package(Package);
    Meeting& get_current_meeting();
    void set_current_meeting(Meeting);

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
    void set_damage(const int min, const int max);
    const int get_min_damage() const {return min_damage;}
    const int get_max_damage() const {return max_damage;}
private:
    Vector<Game_state*> states;
    int currentstate;
    Sector sectors[5][5];
    int currentsector_x = -1;
    int currentsector_y = -1;
    bool winning = true;
    Package current_package = Package();
    Meeting current_meeting = Meeting();
    int min_damage;
    int max_damage;
};


#endif //CPP_HERKANSING_GAME_STATE_CONTEXT_H
