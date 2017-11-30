//
// Created by administrator on 27-11-17.
//

#include "../../Headers/State/Sector_state.h"
#include "../../Headers/Models/Sector_item.h"
#include "../../Headers/Models/Sector_emty.h"
#include "../../Headers/Libs/String.h"
#include "../../Headers/Libs/Random.h"
#include "../../Headers/Models/Sector_planeet.h"
#include "../../Headers/Models/Sector_asteroide.h"
#include "../../Headers/Models/Sector_ontmoeting.h"
#include "../../Headers/Models/Sector_ship.h"

Sector_state::~Sector_state() {
    for(auto& x : field){
        for(auto& y: x){
            delete y;
        }
    }
}

void Sector_state::create_field(Sector sector) {


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                field[i][j] = new Sector_emty() ;
        }
    }

    Random random;
    // add random planets

        int counter_pla = 0;
        //loops untill al the planates are chosen
        while(counter_pla < sector.get_pla()){
            auto x =  random.get_random(0,9);
            auto y =  random.get_random(0,9);
            if( field[x][y]->get_type() == '.'){
                delete field[x][y];
                field[x][y] = new Sector_planeet();
                counter_pla++;
            }
        }


    // add random astoids
        int counter_astr = 0;
        //loops untill al the astroids are chosen
        while(counter_astr < sector.get_astr()){
            auto x =  random.get_random(0,9);
            auto y =  random.get_random(0,9);
            if( field[x][y]->get_type() == '.'){
                delete field[x][y];
                field[x][y] = new Sector_asteroide();
                counter_astr++;
            }
        }

    // add random ontmoetingen
    int counter_ont = 0;
    //loops untill al the ontmoetingen are chosen
    while(counter_ont < sector.get_ont()){
        auto x =  random.get_random(0,9);
        auto y =  random.get_random(0,9);
        if( field[x][y]->get_type() == '.'){
            delete field[x][y];
            field[x][y] = new Sector_ontmoeting();
            counter_ont++;
        }
    }

    int counter_ship = 0;
    //loops untill al the ontmoetingen are chosen
    while(counter_ship < 1){
        auto x =  random.get_random(0,9);
        auto y =  random.get_random(0,9);
        if( field[x][y]->get_type() == '.'){
            delete field[x][y];
            field[x][y] = new Sector_ship();
            counter_ship++;
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

    create_field(sector);
    draw_field();
}