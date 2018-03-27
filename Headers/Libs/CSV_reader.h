//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_CSV_READER_H
#define CPP_HERKANSING_CSV_READER_H

#include "Vector.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "String.h"
#include "../Models/Package.h"


using namespace std;

class CSV_reader {
public:
    Vector<Package> get_data(String path);
};


#endif //CPP_HERKANSING_CSV_READER_H
