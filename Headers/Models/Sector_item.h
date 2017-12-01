//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_ITEM_H
#define CPP_HERKANSING_SECTOR_ITEM_H


class Sector_item {
public:

    virtual void print() const{};
    virtual char get_type() const{
        return '#';
    };


};


#endif //CPP_HERKANSING_SECTOR_ITEM_H
