//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_ONTMOETING_H
#define CPP_HERKANSING_SECTOR_ONTMOETING_H


#include "Sector_item.h"

class Sector_ontmoeting : public Sector_item {
public:
    Sector_ontmoeting():Sector_item('*'){};
    char get_type() const override;
};


#endif //CPP_HERKANSING_SECTOR_ONTMOETING_H
