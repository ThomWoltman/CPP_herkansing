//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_ASTEROIDE_H
#define CPP_HERKANSING_SECTOR_ASTEROIDE_H


#include "Sector_item.h"

class Sector_asteroide : public Sector_item {
public:
    Sector_asteroide() : Sector_item('O'){};
    char get_type() const override;
};


#endif //CPP_HERKANSING_SECTOR_ASTEROIDE_H
