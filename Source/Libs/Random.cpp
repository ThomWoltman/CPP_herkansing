//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include <random>
#include <ctime>
#include "../../Headers/Libs/Random.h"

using namespace std;

const int Random::get_random(const int first, const int second) const {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(first, second);

    int result = distribution(gen);
    return result;
}

