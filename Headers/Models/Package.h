//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_PAKAGE_H
#define CPP_HERKANSING_PAKAGE_H

#include "../Libs/String.h"

class Package{
public:
    Package():inhoud{""},bestemming{""}{};
    Package(const char *inhoud, const char *bestemming): inhoud{inhoud},bestemming{bestemming}{};
    ~Package(){};

    friend ostream& operator<<(ostream& strm, Package &package) {
        if(strm){
            strm << "package: ";
            strm << package.inhoud << " - " << package.bestemming << " --> ";
            if(package.sector_x != -1){
                strm << "Sector (" << package.sector_x << "," << package.sector_y << ")";
                strm << " - ";
                strm << "Planet (" << package.x << "," << package.y << ")";
            }
        }

        return strm;
    }

    const bool is_empty() const{
        return inhoud.is_empty() && bestemming.is_empty();
    }

    void set_planet_position(const int sec_x, const int sec_y, const int planet_x, const int planet_y){
        sector_x = sec_x;
        sector_y = sec_y;
        x = planet_x;
        y = planet_y;
    }

private:
    String inhoud;
    String bestemming;
    int sector_x = -1;
    int sector_y = -1;
    int x = -1;
    int y = -1;
};

#endif //CPP_HERKANSING_PAKAGE_H
