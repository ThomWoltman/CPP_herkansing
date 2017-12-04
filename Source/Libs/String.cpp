//
// Created by administrator on 23-11-17.
//

#include "../../Headers/Libs/String.h"

const bool String::is_empty() const {
    return cstring == nullptr ||  cstring[0] == '\0';
}

