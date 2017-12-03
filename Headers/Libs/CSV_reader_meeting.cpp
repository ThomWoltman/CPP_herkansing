//
// Created by administrator on 3-12-17.
//

#include "CSV_reader_meeting.h"

Vector<Meeting> CSV_reader_meeting::get_data(String path) {
    Vector<Meeting> data;

    ifstream ip(path.get_string());
    if (!ip.is_open()) cout << "ERROR: FIle Open" << endl;
    int counter1 = 0;

    //loops untill there are no lines in document
    while (ip) {
        char line[500];

        if(counter1 == 24){
            int i = 1;
        }

        ip.getline(line, 500, '\r');

        if(line[0] == '\000'){
            break;
        }

        stringstream sentence {line};

        char line1[100];
        char line2[100];
        char line3[100];
        char line4[100];
        char line5[100];
        char line6[100];

        sentence.getline(line1, 100, ';');
        sentence.getline(line2, 100, ';');
        sentence.getline(line3, 100, ';');
        sentence.getline(line4, 100, ';');
        sentence.getline(line5, 100, ';');
        sentence.getline(line6, 100, ';');

        Meeting element;

        if(counter1 != 0)
            element = Meeting {line1+1, line2,line3, line4,line5,line6};
        else
            element = Meeting {line1+1, line2,line3, line4,line5,line6};

        counter1++;

        // make city object
        if(!element.is_empty())
            data.push_back(element);
    }

    return data;
}