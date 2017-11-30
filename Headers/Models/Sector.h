//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_H
#define CPP_HERKANSING_SECTOR_H

#include <iostream>

using namespace std;

class Sector {
public:
    Sector(int,int,int);
    Sector();

    friend ostream& operator<<(ostream& strm, const Sector &sector){
        if(strm){
            strm << sector.astr << sector.ont << sector.pla;
        }

        return strm;
    };
    const int get_astr();
    const int get_ont();
    const int  get_pla();


private:
    int astr;
    int ont;
    int pla;

};


#endif //CPP_HERKANSING_SECTOR_H
