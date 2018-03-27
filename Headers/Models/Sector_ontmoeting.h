//
// Created by administrator on 28-11-17.
//

#ifndef CPP_HERKANSING_SECTOR_ONTMOETING_H
#define CPP_HERKANSING_SECTOR_ONTMOETING_H


#include "Sector_item.h"

class Sector_ontmoeting : public Sector_item {
public:
    Sector_ontmoeting(int x, int y):Sector_item('*'), x{x}, y{y}, is_moved{false}{};
    char get_type() const override;
    const int get_x() const {return x;};
    const int get_y() const {return y;};
    void set_x(const int new_x) {x = new_x;}
    void set_y(const int new_y) {y = new_y;};
    void toggle_is_moved(){is_moved = !is_moved;}
    const bool get_is_moved() {return is_moved;}
private:
    bool is_moved;
    int x;
    int y;
};


#endif //CPP_HERKANSING_SECTOR_ONTMOETING_H
