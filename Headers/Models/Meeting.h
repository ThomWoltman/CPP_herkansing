//
// Created by administrator on 3-12-17.
//

#ifndef CPP_HERKANSING_MEETING_H
#define CPP_HERKANSING_MEETING_H


#include "../Libs/String.h"

class Meeting {
public:
    Meeting():meeting{""}{};
    Meeting(const char *meeting, const char *gevecht_fry,const char *tekst_leela,const char *onderhandeling_leela,const char *succes_bender,const char *gefaald_bender)
            : meeting{meeting},gevecht_fry{gevecht_fry}, tekst_leela{tekst_leela},onderhandeling_leela{onderhandeling_leela},succes_bender{succes_bender}, gefaald_bender{gefaald_bender}
    {};
    ~Meeting(){};

    friend ostream& operator<<(ostream& strm, Meeting &meeting) {
        if(strm){
            strm << meeting.meeting ;
        }

        return strm;
    }

    const bool is_empty() const{
        return meeting.is_empty();
    }

    String meeting ;
    String gevecht_fry;
    String tekst_leela;
    String onderhandeling_leela;
    String succes_bender;
    String gefaald_bender;
private:



};


#endif //CPP_HERKANSING_MEETING_H
