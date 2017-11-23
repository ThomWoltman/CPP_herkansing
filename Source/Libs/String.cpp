//
// Created by administrator on 23-11-17.
//

#include "../../Headers/Libs/String.h"



String::String(const char *charArray) : string{charArray} {

}

const bool String::equals(const char *char_array) const {
    if(string[0] == '\0')
        return false;

    int i = 0;

    for(i;string[i]!='\0';i++){
        if(string[i]!=char_array[i])
            return false;
    }

    return char_array[i] == '\0';
}

