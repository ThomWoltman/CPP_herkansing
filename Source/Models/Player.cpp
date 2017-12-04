//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../../Headers/Models/Player.h"

Player::Player() : damage{0}{

}

void Player::repair() {
    damage = 0;
}

void Player::add_damage(const int dmg) {
    damage += dmg;
}

void Player::add_win_point() { win_points++;}
void Player::remove_win_point() {
    if(win_points > 0){
        win_points--;
    }
}


const int Player::get_win_point() const {return win_points;}

const int Player::get_damage() const { return damage;}