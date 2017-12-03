
#include "../../Headers/Models/Sector.h"
#include "../../Headers/Libs/Random.h"
#include "../../Headers/Models/Sector_planeet.h"
#include "../../Headers/Models/Sector_asteroide.h"
#include "../../Headers/Models/Sector_ontmoeting.h"
#include "../../Headers/Models/Sector_ship.h"
#include "../../Headers/Models/Sector_empty.h"

Sector::Sector(int ast, int ont, int pla):astr{ast},ont{ont},pla{pla}, is_initialized{false} {}

Sector::Sector(): is_initialized{false} {
    Random rdm;

    astr = rdm.get_random(0,9);
    ont = rdm.get_random(0,3);
    pla = rdm.get_random(0,2);
}

Sector::~Sector() {
    if(is_initialized){
        for(int y = 0; y < 10; y++){
            for(int x = 0; x < 10; x++){
                delete field[y][x];
            }
        }
    }
}

void Sector::initialize(const int x_pos, const int y_pos) {
    if(!is_initialized){
        player_x = x_pos;
        player_y = y_pos;

        create_field();
        is_initialized = true;
    }
}

void Sector::create_field() {
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            field[y][x] = new Sector_emty();
        }
    }

    Random random;

    if(player_x != -1 && player_y != -1){ // player position is set
        delete field[player_y][player_x];
        field[player_y][player_x] = new Sector_ship();
    }
    else{
        bool is_placed = false;

        while(!is_placed){
            auto x =  random.get_random(0,9);
            auto y =  random.get_random(0,9);
            if(field[y][x]->get_type() == '.') {
                player_x = x;
                player_y = y;
                delete field[y][x];
                field[y][x] = new Sector_ship();
                is_placed = true;
            }
        }
    }
    // add random planets

    int counter_pla = 0;
    //loops until al the planetes are chosen
    while(counter_pla < pla){
        auto x =  random.get_random(0,9);
        auto y =  random.get_random(0,9);
        if(field[y][x]->get_type() == '.') {
            delete field[y][x];
            field[y][x] = new Sector_planeet();
            counter_pla++;
        }
    }

    // add random astoids
    int counter_astr = 0;
    //loops untill al the astroids are chosen
    while(counter_astr < astr){
        auto x =  random.get_random(0,9);
        auto y =  random.get_random(0,9);
        if(field[y][x]->get_type() == '.'){
            delete field[y][x];
            field[y][x] = new Sector_asteroide();
            counter_astr++;
        }
    }

    // add random ontmoetingen
    int counter_ont = 0;
    //loops untill al the ontmoetingen are chosen
    while(counter_ont < ont){
        auto x =  random.get_random(0,9);
        auto y =  random.get_random(0,9);
        if(field[y][x]->get_type() == '.') {
            delete field[y][x];
            field[y][x] = new Sector_ontmoeting();
            counter_ont++;
        }
    }
}

const int  Sector::get_astr() {
    return astr;
}
const int Sector::get_ont() {
    return ont;
}
const int Sector::get_pla() {
    return pla;
}

bool Sector::move_left() {
    bool out_of_bounds = is_out_of_bounds(player_x, player_y, player_x-1, player_y);
    if(!out_of_bounds && field[player_y][player_x-1]->get_type() == '.'){
        swap_fields(player_x, player_y, player_x-1, player_y);
        player_x -= 1;
    }
    return !out_of_bounds;
}

bool Sector::move_right() {
    bool out_of_bounds = is_out_of_bounds(player_x, player_y, player_x+1, player_y);
    if(!out_of_bounds && field[player_y][player_x+1]->get_type() == '.'){
        swap_fields(player_x, player_y, player_x+1, player_y);
        player_x += 1;
    }
    return !out_of_bounds;
}

bool Sector::move_down() {
    bool out_of_bounds = is_out_of_bounds(player_x, player_y, player_x, player_y+1);
    if(!out_of_bounds && field[player_y+1][player_x]->get_type() == '.'){
        swap_fields(player_x, player_y, player_x, player_y+1);
        player_y += 1;
    }
    return !out_of_bounds;
}

bool Sector::move_up() {
    bool out_of_bounds = is_out_of_bounds(player_x, player_y, player_x, player_y-1);
    if(!out_of_bounds && field[player_y-1][player_x]->get_type() == '.'){
        swap_fields(player_x, player_y, player_x, player_y-1);
        player_y -= 1;
    }
    return !out_of_bounds;
}
bool Sector::next_planet() {
    bool next_planet = false;
    if((!is_out_of_bounds(player_x, player_y, player_x, player_y-1)) && field[player_y-1][player_x]->get_type() == '@'){
       next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x-1, player_y-1))&&field[player_y-1][player_x-1]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x-1, player_y )) && field[player_y][player_x-1]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x+1, player_y+1)) && field[player_y+1][player_x+1]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x, player_y+1)) && field[player_y+1][player_x]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x+1, player_y))&&field[player_y][player_x+1]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x+1, player_y-1))&&field[player_y-1][player_x+1]->get_type() == '@'){
        next_planet = true;
    }
    if((!is_out_of_bounds(player_x, player_y, player_x-1, player_y+1))&&field[player_y+1][player_x-1]->get_type() == '@'){
        next_planet = true;
    }

    return next_planet;
}

void Sector::move_meetings() {
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            if(field[y][x]->get_type() =='*'){
               int t_x = x;
               int t_y = y;
                if(player_x < x && field[y][x-1]->get_type() != 'P'){
                    swap_fields(t_x, t_y, t_x-1, t_y);
                    t_x = t_x-1;
                }else if(player_y < t_y && field[y-1][x]->get_type() != 'P'){
                    swap_fields(t_x, t_y, t_x, t_y-1);
                    t_y = t_y-1;
                }else if(player_x > x && field[y][x+1]->get_type() != 'P'){
                    swap_fields(t_x, t_y, t_x+1, t_y);
                    t_x = t_x+1;
                }else if(player_y > t_y && field[y+1][x]->get_type() != 'P'){
                    swap_fields(t_x, t_y, t_x, t_y+1);
                    t_y = t_y+1;


                }
            }
        }
    }
}

const bool Sector::is_out_of_bounds(int x1, int y1, int x2, int y2) const {
    return x2 > 9 || x2 < 0 || y2 < 0 || y2 > 9 || x1 < 0 || x1 > 9 || y1 > 9 || y1 < 0;
}

bool Sector::swap_fields(int x1, int y1, int x2, int y2) {
    bool can_swap = !(x2 > 9 || x2 < 0 || y2 < 0 || y2 > 9 || x1 < 0 || x1 > 9 || y1 > 9 || y1 < 0) && field[y2][x2]->get_type() == '.';
    if(can_swap) {
        auto *f = field[y1][x1];
        field[y1][x1] = field[y2][x2];
        field[y2][x2] = f;
    }
    return can_swap;
}
