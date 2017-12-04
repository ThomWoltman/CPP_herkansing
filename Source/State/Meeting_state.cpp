//
// Created by administrator on 3-12-17.
//

#include "../../Headers/State/Meeting_state.h"
#include "../../Headers/Libs/CSV_reader_meeting.h"
#include "../../Headers/Libs/Random.h"

Meeting_state::Meeting_state() {}
Meeting_state::~Meeting_state() {}
void Meeting_state::run(Player &player, Game_state_context &context) {
    cout<<"Meeting state";
    if(context.get_current_meeting().is_empty()){
        CSV_reader_meeting reader;
        String s;
        s.operator=("/home/administrator/Documents/CPP_herkansing/Data/Ontmoetingen.csv");
        auto b = reader.get_data(s);

        Random random;
        int random_number = random.get_random(0, b.length());
        context.set_current_meeting(b[random_number]);

    }
    cout << context.get_current_meeting();

    cout<<"Which crew member do you want to chose"<<endl;
    cout<<"-bender"<<endl;
    cout<<"-leella"<<endl;
    cout<<"-fry"<<endl;

    handle_input(player,context);
}

void Meeting_state::handle_input(Player &player, Game_state_context &context) {
    String input;
    cin >> input;

    if(input == "bender" ||input == "b"){
    Random random;
        int random_number = random.get_random(0,1);
        if(random_number ==0 ){
            cout << context.get_current_meeting().gefaald_bender<< endl;
            context.set_state(3);


        }else{
            cout << context.get_current_meeting().succes_bender<< endl;
            context.set_state(1);
            context.set_current_meeting(Meeting());

        }
    }
    if(input == "leella" ||input == "l"){
        cout << context.get_current_meeting().tekst_leela<< endl;

        cout << context.get_current_meeting().onderhandeling_leela<< endl;
        String outcome = context.get_current_meeting().onderhandeling_leela;
        Vector<char> parse(300);

        for(int x = 0 ; x < sizeof(outcome.get_string()); x ++){
            if(outcome.get_string()[x] == '['){
                int counter = 0;
                while(outcome.get_string()[x] != ']'){
                    parse.push_back(outcome.get_string()[x])  ;
                    x++;
                    counter++;
                }
                parse.push_back(']');
                break;
            }
        }

        char parse_char[parse.length()];
        for(int i = 0 ; i < parse.length(); i++){
            parse_char[i] = parse[i];
        }
        outcome = parse_char;

        if(outcome.operator==("[0]")){
            context.set_state(1);
            context.set_current_meeting(Meeting());
        }
        else if(outcome == "[vp+1]"){
            player.add_win_point();
            context.set_state(1);
            context.set_current_meeting(Meeting());

        }
        else if(outcome == "[vp-1]"){
            context.set_state(1);
            context.set_current_meeting(Meeting());
        }
        else if(outcome == "[repair]"){
            context.set_state(1);
            context.set_current_meeting(Meeting());
        }else{

        }


    }
    if(input == "fry" ||input == "f"){
        cout << context.get_current_meeting().gevecht_fry<< endl;
        context.set_state(3);
    }
}