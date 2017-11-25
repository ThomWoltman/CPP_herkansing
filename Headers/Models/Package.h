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
    String inhoud;
    String bestemming;

private:


};

#endif //CPP_HERKANSING_PAKAGE_H
