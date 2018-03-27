//
// Created by administrator on 3-12-17.
//

#ifndef CPP_HERKANSING_CSV_READER_MEETING_H
#define CPP_HERKANSING_CSV_READER_MEETING_H


#include "Vector.h"
#include "../Models/Meeting.h"
#include <iostream>
#include <fstream>
#include <sstream>

class CSV_reader_meeting {
public:
    Vector<Meeting> get_data(String path);

};


#endif //CPP_HERKANSING_CSV_READER_MEETING_H
