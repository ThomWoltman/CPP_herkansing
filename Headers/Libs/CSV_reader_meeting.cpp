//
// Created by administrator on 3-12-17.
//

#include "CSV_reader_meeting.h"

Vector<Meeting> CSV_reader_meeting::get_data(String path) {
    Vector<Meeting> data;

    ifstream ip(path.get_string());
    if (!ip.is_open()) cout << "ERROR: FIle Open" << endl;
    int counter1 = 0;

    Meeting element;

    //loops untill there are no lines in document
    while (ip) {
        char line[500];

        ip.getline(line, 500, '\n');

        if(line[0] == '\000'){
            break;
        }

        stringstream sentence {line};

        char line1[200];
        char line2[200];
        char line3[200];
        char line4[200];
        char line5[200];
        char line6[200];

        sentence.getline(line1, 200, ';');
        sentence.getline(line2, 200, ';');
        sentence.getline(line3, 200, ';');
        sentence.getline(line4, 200, ';');
        sentence.getline(line5, 200, ';');
        sentence.getline(line6, 200, ';');

        if(counter1 != 0)
            element = Meeting {line1, line2,line3, line4,line5,line6};
        else
            element = Meeting {line1+3, line2,line3, line4,line5,line6};

        counter1++;

        // make city object
        if(!element.is_empty())
            data.push_back(element);
    }

    return data;
}