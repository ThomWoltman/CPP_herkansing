//
// Created by administrator on 27-11-17.
//

#include "../../Headers/State/Sector_state.h"
#include "../../Headers/Models/Sector_item.h"
#include "../../Headers/Models/Sector_emty.h"
#include "../../Headers/Libs/String.h"

Sector_state::~Sector_state() {
    for(auto& x : field){
        for(auto& y: x){
            delete y;
        }
    }
}

void Sector_state::create_field() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                field[i][j] = new Sector_emty() ;
        }
    }
}

void Sector_state::draw_field() {
    for (int i = 0; i < 10; i++) {
        cout<< endl;

        for (int j = 0; j < 10; j++) {
            field[i][j]->print();
        }
    }
}

void Sector_state::run(Player &player, Game_state_context &context) {

    Sector sector = context.get_current_sector();
    std::cout << "Sector" << std::endl;
    std::cout << sector << std::endl;

    create_field();
    draw_field();
}