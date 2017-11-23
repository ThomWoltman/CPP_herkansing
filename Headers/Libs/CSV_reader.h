//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_CSV_READER_H
#define CPP_HERKANSING_CSV_READER_H

#include "Array.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSV_reader.h"
#include "String.h"
#include "../Models/Pakage.h"


using namespace std;

class CSV_reader {
public:
    Array<Pakage> get_data(String path);
};


#endif //CPP_HERKANSING_CSV_READER_H
