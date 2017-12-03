//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_ITEM_H
#define CPP_HERKANSING_SECTOR_ITEM_H

#include <iostream>

using namespace std;

class Sector_item {
public:
    explicit Sector_item(const char t):type{t}{};
    virtual void print() const{};
    virtual char get_type() const{
        return type;
    };
    friend ostream& operator<<(ostream& strm, Sector_item& astr) {
        if(strm){
            strm << astr.type;
        }

        return strm;
    }
protected:
    const char type = '#';
};


#endif //CPP_HERKANSING_SECTOR_ITEM_H
