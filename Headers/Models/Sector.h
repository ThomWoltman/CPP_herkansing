//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_H
#define CPP_HERKANSING_SECTOR_H

#include <iostream>
#include "Sector_item.h"
#include "../Libs/Vector.h"
#include "Sector_planeet.h"
#include "Sector_ontmoeting.h"

using namespace std;

class Sector {
public:
    Sector(int,int,int);
    Sector();
    Sector(const Sector& sector){

    }
    Sector(Sector&& other) noexcept {
        if(is_initialized){
            for(int y = 0; y < 10; y++){
                for(int x = 0; x < 10; x++){
                    delete field[y][x];
                }
            }
        }

        field[0][0] = other.field[0][0];
        is_initialized = other.is_initialized;
        astr = other.astr;
        ont = other.ont;
        pla = other.pla;
        player_x = other.player_x;
        player_y = other.player_y;
    }

    Sector&operator=(const Sector& other){
        if(is_initialized){
            for(int y = 0; y < 10; y++){
                for(int x = 0; x < 10; x++){
                    delete field[y][x];
                }
            }
        }

        field[0][0] = other.field[0][0];
        is_initialized = other.is_initialized;
        astr = other.astr;
        ont = other.ont;
        pla = other.pla;
        player_x = other.player_x;
        player_y = other.player_y;
    }

    ~Sector();

    friend ostream& operator<<(ostream& strm, const Sector &sector){
        if(strm){

            if(sector.is_initialized){

                for(int y = 0; y < 10; y++){
                    for(int x = 0; x < 10; x++){
                        strm << *sector.field[y][x];
                    }
                    strm << endl;
                }
            }
        }

        return strm;
    };
    const int get_astr();
    const int get_ont();
    const int get_pla();
    void initialize(int x_pos = -1, int y_pos = -1);
    void move_meetings();

    bool move_left();
    bool move_right();
    bool move_up();
    bool move_down();
    bool next_to(const char);
    Sector_planeet* get_planet();
    void remove(int x, int y);
    Sector_ontmoeting* is_next_to_meeting();

    const int get_player_x() const {return player_x;};
    const int get_player_y() const {return player_y;};

private:
    bool is_initialized;
    int astr;
    int ont;
    int pla;
    int player_x;
    int player_y;
    Sector_item* field[10][10];
    void create_field();
    bool swap_fields(int x1, int y1, int x2, int y2);
    const bool is_out_of_bounds(int x1, int y1, int x2, int y2) const;
};


#endif //CPP_HERKANSING_SECTOR_H
