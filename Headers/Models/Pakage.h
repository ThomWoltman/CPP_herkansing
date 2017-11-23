//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_PAKAGE_H
#define CPP_HERKANSING_PAKAGE_H

#include "../Libs/String.h"

class Pakage{
public:
    Pakage():inhoud{""},bestemming{""}{};
    Pakage(char * inhoud, char *bestemming): inhoud{inhoud},bestemming{bestemming}{};
    String  inhoud;
    String bestemming;

private:


};

#endif //CPP_HERKANSING_PAKAGE_H
