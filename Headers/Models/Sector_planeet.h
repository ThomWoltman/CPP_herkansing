//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_PLANEET_H
#define CPP_HERKANSING_SECTOR_PLANEET_H


#include "Sector_item.h"

class Sector_planeet : public Sector_item {
public:
    Sector_planeet(int x, int y):Sector_item('@'), x{x}, y{y}{};
    char get_type() const override;
    const int get_x() const {return x;};
    const int get_y() const {return y;};
private:
    int x;
    int y;
};


#endif //CPP_HERKANSING_SECTOR_PLANEET_H
