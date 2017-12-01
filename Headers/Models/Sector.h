//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_H
#define CPP_HERKANSING_SECTOR_H

#include <iostream>
#include "Sector_item.h"
#include "../Libs/Vector.h"

using namespace std;

class Sector {
public:
    Sector(int,int,int);
    Sector();

    ~Sector();

    friend ostream& operator<<(ostream& strm, const Sector &sector){
        if(strm){

            if(sector.is_initialized){

                for(int y = 0; y < 10; y++){
                    for(int x = 0; x < 10; x++){
                        strm << sector.field[y][x]->get_type();
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
    void initialize();

    bool move_left();
    bool move_right();
    bool move_up();
    bool move_down();

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
};


#endif //CPP_HERKANSING_SECTOR_H
