
#include "../../Headers/Models/Sector.h"
#include "../../Headers/Libs/Random.h"

Sector::Sector(int ast, int ont, int pla):astr{ast},ont{ont},pla{pla} {}

Sector::Sector() {
    Random rdm;

    astr = rdm.get_random(0,9);
    ont = rdm.get_random(0,3);
    pla = rdm.get_random(0,2);
}

Sector::~Sector() {
//    for(auto& x : field){
//        for(auto& y: x){
//            delete y;
//        }
//    }
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

