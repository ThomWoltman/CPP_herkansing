//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_SHIP_H
#define CPP_HERKANSING_SECTOR_SHIP_H


#include "Sector_item.h"

class Sector_ship : public Sector_item {
public:
    Sector_ship():Sector_item('P'){};
    char get_type() const override;
};


#endif //CPP_HERKANSING_SECTOR_SHIP_H
