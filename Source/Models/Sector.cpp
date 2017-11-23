//
// Created by administrator on 23-11-17.
//

#include "../../Headers/Models/Sector.h"
#include <iostream>

Sector::Sector(int ast, int ont, int pla):astr{ast},ont{ont},pla{pla} {}
void Sector::print() {
    std::cout << astr<< ont << pla;
}