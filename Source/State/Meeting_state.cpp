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

    CSV_reader_meeting reader;
    String s;
    s.operator=("/home/administrator/Documents/CPP_herkansing/Data/Ontmoetingen.csv");
    auto b = reader.get_data(s);

    Random random;
    int random_number = random.get_random(0, b.length());
    cout << b[random_number];
    
    String input;
    cin >> input;

}