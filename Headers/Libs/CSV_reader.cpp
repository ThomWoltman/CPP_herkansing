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
    while (ip.good()) {


        string line;

        getline(ip, line, '\r');

        stringstream sentence;
        if (counter1 != 0)
            line.erase(0, 1);

        sentence << line;
        string word;
        string word2;


        getline(sentence, word, ';');
        auto inhoud = word.c_str();
        getline(sentence, word2, ';');
        auto bestemming = word2.c_str();

        Package element {inhoud, bestemming};


        counter1++;

        // make city object
        data.push_back(element);
    }

    return data;
};