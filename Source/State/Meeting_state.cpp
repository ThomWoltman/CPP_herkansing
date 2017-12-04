//
// Created by administrator on 3-12-17.
//

#include "../../Headers/State/Meeting_state.h"
#include "../../Headers/Libs/CSV_reader_meeting.h"
#include "../../Headers/Libs/Random.h"
#include "../../Headers/State/Fight_state.h"

Meeting_state::Meeting_state() {}
Meeting_state::~Meeting_state() {}
void Meeting_state::run(Player &player, Game_state_context &context) {
    cout<<"Meeting state" << endl;
    if(context.get_current_meeting().is_empty()){
        CSV_reader_meeting reader;
        String s;
        //s.operator=("/home/administrator/Documents/CPP_herkansing/Data/Ontmoetingen.csv");
        s.operator=("/home/administrator/CLionProjects/CPP_herkansing/Data/Ontmoetingen.csv");
        meetings = reader.get_data(s);
    }
    Random random;
    int random_number = random.get_random(0, meetings.length()-1);
    context.set_current_meeting(meetings[random_number]);

    cout << "Meeting: "<< context.get_current_meeting() << endl;

    cout<<"Which crew member do you want to choose"<<endl;
    cout<<"[bender]-[leella]-[fry]"<<endl;

    handle_input(player,context);
}

void Meeting_state::handle_input(Player &player, Game_state_context &context) {
    String input;
    cin >> input;

    if(input == "bender" ||input == "b"){
    Random random;
        int random_number = random.get_random(0,1);
        String str;
        auto& meeting = context.get_current_meeting();
        if(random_number ==0 ){
            str = context.get_current_meeting().gefaald_bender;
        }else{
            str = context.get_current_meeting().succes_bender;
        }
        handle_consequence(str, player,context);
    }
    else if(input == "leella" ||input == "l"){
        cout << context.get_current_meeting().tekst_leela<< endl;

        String consequence = context.get_current_meeting().onderhandeling_leela;

        handle_consequence(consequence, player, context);
    }
    else if(input == "fry" ||input == "f"){
        String str = context.get_current_meeting().gevecht_fry;
        handle_consequence(str, player, context);
    }
    else{
        handle_input(player, context);
    }
}

void Meeting_state::handle_consequence(String& str, Player &player, Game_state_context &context) {
    if(str == "[0]"){ // niks
        context.set_state(1);
        cout << "nothing happened .." << endl;
    }
    else if(str == "[vp+1]"){ //+1 overwinning
        cout << "win point!!" << endl;
        player.add_win_point();
        context.set_state(1);
    }
    else if(str == "[vp-1]"){ //-1 overwinning
        cout << "you lost a win point =(" << endl;
        player.remove_win_point();
        context.set_state(1);
    }
    else if(str == "[repair]"){ // alle schadepunten repareren
        cout << "ship is repaired!" << endl;
        player.repair();
        context.set_state(1);
    }
    else if(str[0] == '['){
        char min[3];
        char max[3];

        int counter = 0;
        int index = 1;

        while(str[index] != '-'){
            min[counter] = str[index];
            counter++;
            index++;
        }
        index++;
        min[counter] = '\0';
        counter = 0;
        while(str[index] != ']'){
            max[counter] = str[index];
            counter++;
            index++;
        }
        max[counter] = '\0';

        context.set_state(3);
        context.set_damage(atoi(min), atoi(max));
    }
    else {
        cout << str << " - string" << endl;
        char text[200];
        int text_counter = 0;
        char consequence[100];
        int consequence_counter = 0;

        bool found_bracket = false;
        for(int i = 0; i < std::strlen(str.get_string()); i++){
            if(found_bracket){
                consequence[consequence_counter] = str[i];
                consequence_counter++;
                if(str[i] == ']'){
                    break;
                }
            }
            else{
                if(str[i] == '['){
                    found_bracket = true;
                    text[text_counter] = '\0';
                    consequence[consequence_counter] = str[i];
                    consequence_counter++;
                }
                else{
                    text[text_counter] = str[i];
                    text_counter++;
                }
            }
        }

        if(text_counter > 0)
            cout << "text:" << text << endl;

        if(consequence_counter > 0){
            cout << "cons:" << consequence << endl;
            String co{consequence};
            handle_consequence(co, player, context);
        }
        else{
            context.set_state(1);
        }
    }
}