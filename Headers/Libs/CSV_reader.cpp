//
// Created by administrator on 23-11-17.
//


#include "CSV_reader.h"

Array<Pakage>  CSV_reader:: get_data(String path) {

    Array<Pakage> data(50);

    ifstream ip(path.string);
    if (!ip.is_open()) cout << "ERROR: FIle Open" << endl;
    int counter1 = 0;


    //loops untill there are no lines in document
    while (ip.good()) {
        auto element = Pakage();

        string name2;
        string name;
        string line2;
        string line;


        getline(ip, line, '\r');

        stringstream sentence;
        if (counter1 != 0) { line.erase(0, 1); }

        sentence << line;
        string word;
        string word2;


        getline(sentence, word, ';');
        element.inhoud = word.c_str();
        getline(sentence, word2, ';');
        element.bestemming = word2.c_str();


        counter1++;

        // make city object
        data.push_back(element);
    }


    return data;
};