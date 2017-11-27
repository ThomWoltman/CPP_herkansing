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
            strm << package.inhoud << " - " << package.bestemming;
        }

        return strm;
    }

    const bool is_empty() const{
        return inhoud.is_empty() && bestemming.is_empty();
    }

private:
    String inhoud;
    String bestemming;

};

#endif //CPP_HERKANSING_PAKAGE_H
