//
// Created by administrator on 3-12-17.
//

#include "Fight_state.h"
#include "../Libs/Random.h"

Fight_state::Fight_state() {};
Fight_state::~Fight_state() {};

void Fight_state::run(Player &player, Game_state_context &context) {
    cout<< "Fight state - " << "round " << round << endl;
    Random random;
    int dmg = random.get_random(context.get_min_damage(), context.get_max_damage());
    player.add_damage(dmg);
    cout<<"Enemy did "<<dmg<<" damage - health = " << player.get_damage()<<endl;

    if(player.get_damage() >= 200){
        cout<<"you lost =("<<endl;
        context.set_state(0);
        round = 1;
        hits = 0;
    }
    else{
        int hit = random.get_random(0,1);
        if(hit == 1){
            cout<<"you hit the enemy! hits("<<hits<<")"<< endl;
            hits++;
            if(hits >= 3){
                context.set_state(1);
                round = 1;
                hits = 0;
            }
        }
        else{
            cout<<"you missed the enemy"<<endl;
        }
    }
    round++;
};

void Fight_state::handle_input(Player &player, Game_state_context &context) {

}

