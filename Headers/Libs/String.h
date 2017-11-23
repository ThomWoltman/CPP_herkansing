//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_STRING_H
#define CPP_HERKANSING_STRING_H


class String {
public:
    const char* string;
    String(const char* charArray);
    const bool equals(const char* char_array) const;
};


#endif //CPP_HERKANSING_STRING_H
