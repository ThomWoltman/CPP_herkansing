//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_H
#define CPP_HERKANSING_SECTOR_H

#include <iostream>
#include "Sector_item.h"

using namespace std;

class Sector {
public:
    Sector(int,int,int);
    Sector();

    ~Sector();

    friend ostream& operator<<(ostream& strm, const Sector &sector){
        if(strm){
            strm << sector.astr << sector.ont << sector.pla;
        }

        return strm;
    };
    const int get_astr();
    const int get_ont();
    const int  get_pla();
    Sector_item* get_field(){
        return field[0][0];
    }

private:
    int astr;
    int ont;
    int pla;
    Sector_item* field[10][10];
};


#endif //CPP_HERKANSING_SECTOR_H
