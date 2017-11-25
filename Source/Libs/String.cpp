//
// Created by administrator on 23-11-17.
//

#include "../../Headers/Libs/String.h"

const void String::print() {

    if(cstring == nullptr)
        return;

    auto temp = cstring;

    for(int i = 0;cstring[i]!='\0';i++){
        cout << cstring[i];
    }

}

const bool String::equals(const char *char_array) const {
    if(cstring[0] == '\0')
        return false;

    int i = 0;

    for(i;cstring[i]!='\0';i++){
        if(cstring[i]!=char_array[i])
            return false;
    }

    return char_array[i] == '\0';
}

