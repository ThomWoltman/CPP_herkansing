//
// Created by administrator on 23-11-17.
//


#include "CSV_reader.h"

Array<Package>  CSV_reader:: get_data(String path) {

    Array<Package> data(50);

    ifstream ip(path.get_string());
    if (!ip.is_open()) cout << "ERROR: FIle Open" << endl;
    int counter1 = 0;

    //loops untill there are no lines in document
    while (ip) {
        char line[200];

        ip.getline(line, 200, '\r');

        stringstream sentence {line};

        char line1[100];
        char line2[100];

        sentence.getline(line1, 100, ';');
        sentence.getline(line2, 100, ';');

        Package element;

        if(counter1 != 0)
            element = Package {line1+1, line2};
        else
            element = Package {line1, line2};

        counter1++;

        // make city object
        data.push_back(element);
    }

    return data;
};