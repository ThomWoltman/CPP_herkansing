//
// Created by administrator on 23-11-17.
//

#include <iostream>
#include "../../Headers/Models/Player.h"

Player::Player(int coins): coins{coins}, damage{0}{

}

void Player::reset_dmg() {
    damage = 0;
}

void Player::add_damage(const int dmg) {
    damage += dmg;
}