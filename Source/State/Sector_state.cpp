#include <limits>
#include "../../Headers/State/Sector_state.h"
#include "../../Headers/Libs/CSV_reader.h"

Sector_state::Sector_state() {
}

Sector_state::~Sector_state() {

}
void Sector_state::pick_up_package(Game_state_context & game_context) {
    int current_x_pos = game_context.get_current_sector_x();
    int current_y_pos = game_context.get_current_sector_y();

    int sector_x = -1;
    int sector_y = -1;
    int planet_x = -1;
    int planet_y = -1;

    int y = 2;
    for(int x = 0; x < 3 && y > -1; x++, y--){
        if(game_context.get_sector(current_x_pos + x, current_y_pos + y)!= nullptr && game_context.get_sector(current_x_pos + x, current_y_pos + y)->get_pla()){
            game_context.get_sector(current_x_pos + x, current_y_pos + y)->initialize();
            planet_x = game_context.get_sector(current_x_pos + x, current_y_pos + y)->get_planet()->get_x();
            planet_y = game_context.get_sector(current_x_pos + x, current_y_pos + y)->get_planet()->get_y();
            sector_x = current_x_pos + x;
            sector_y = current_y_pos + y;
            break;
        }
        else if(game_context.get_sector(current_x_pos - x, current_y_pos - y) != nullptr && game_context.get_sector(current_x_pos - x, current_y_pos - y)->get_pla() > 0){
            game_context.get_sector(current_x_pos - x, current_y_pos - y)->initialize();
            planet_x = game_context.get_sector(current_x_pos - x, current_y_pos - y)->get_planet()->get_x();
            planet_y = game_context.get_sector(current_x_pos - x, current_y_pos - y)->get_planet()->get_y();
            sector_x = current_x_pos - x;
            sector_y = current_y_pos - y;
            break;
        }
        else if(game_context.get_sector(current_x_pos + x, current_y_pos - y)!=nullptr&&game_context.get_sector(current_x_pos + x, current_y_pos - y)->get_pla() > 0){
            game_context.get_sector(current_x_pos + x, current_y_pos - y)->initialize();
            planet_x = game_context.get_sector(current_x_pos + x, current_y_pos - y)->get_planet()->get_x();
            planet_y = game_context.get_sector(current_x_pos + x, current_y_pos - y)->get_planet()->get_y();
            sector_x = current_x_pos + x;
            sector_y = current_y_pos - y;
            break;
        }
        else if(game_context.get_sector(current_x_pos - x, current_y_pos + y)!= nullptr&&game_context.get_sector(current_x_pos - x, current_y_pos + y)->get_pla() > 0){
            game_context.get_sector(current_x_pos - x, current_y_pos + y)->initialize();
            planet_x = game_context.get_sector(current_x_pos - x, current_y_pos + y)->get_planet()->get_x();
            planet_y = game_context.get_sector(current_x_pos - x, current_y_pos + y)->get_planet()->get_y();
            sector_x = current_x_pos - x;
            sector_y = current_y_pos + y;
            break;
        }
    }
    if(sector_x == -1){
        cout << "cannot find delivery location ... unable to pick-up package" << endl;
        return;
    }

    CSV_reader reader;
    //String path("/home/administrator/Documents/CPP_herkansing/Data/Pakketjes.csv"); // glenn local path
    String path("/home/administrator/CLionProjects/CPP_herkansing/Data/Pakketjes.csv"); // thom local path
    auto b = reader.get_data(path);

    for(int i = 0; i < b.length() ;i++){
        std::cout << i << ". ";
        std::cout << b[i] << std::endl;
    }
    std::cout << "which package do you want to pick up?" << std::endl;

    bool corect_input = false;
    int index = -1;

    cout << "input: ";

    while(!corect_input){
        if(std::cin >> index){
            if(-1 < index && index < b.length()){
                auto pkg = b[index];
                pkg.set_planet_position(sector_x, sector_y, planet_x, planet_y);
                game_context.set_current_package(pkg);
                corect_input = true;
            }
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Sector_state::run(Player &player, Game_state_context &context) {
    if(player.get_win_point() >= 10){
        std::cout << "you won!!!!!" << std::endl;
        context.set_state(0);
        return;
    }
    auto pkg = context.get_current_package();
    std::cout << "win points: " << player.get_win_point() << std::endl;
    std::cout << "Sector" << std::endl;
    std::cout << "x = " << context.get_current_sector_x() << std::endl;
    std::cout << "y = " << context.get_current_sector_y() << std::endl;
    std::cout << context.get_current_sector() << std::endl;
    std::cout << context.get_current_package() << std::endl;

    auto meeting = context.get_current_sector().is_next_to_meeting();
    if(meeting){
        context.get_current_sector().remove(meeting->get_x(), meeting->get_y());
        context.set_state(2);
    }
    else{
        std::cout << "move: [w]-[a]-[s]-[d]" << std::endl << "actions: ";
        if(context.get_current_sector().next_to('@')){
            std::cout << "[pick up(p)]-";
        }

        if(!pkg.is_empty() && context.get_current_sector().next_to('@') && context.get_current_sector_x() == pkg.get_sector_x() && context.get_current_sector_y() == pkg.get_sector_y()){
            int difference_x = std::abs(pkg.get_planet_x() - context.get_current_sector().get_player_x());
            int difference_y = std::abs(pkg.get_planet_y() - context.get_current_sector().get_player_y());
            if(difference_x + difference_y <=1){
                std::cout << "[deliver(e)]-";
            }
        }
        std::cout << "[view package(v)]-[do nothing(n)]-[quit(q)]: " << std::endl;
        handle_input(player, context);
        context.get_current_sector().move_meetings();
    }
}

void Sector_state::handle_input(Player &player, Game_state_context &context) {
    std::cout << "input: ";

    String str;
    std::cin >> str;

    if(str == "d"){
        if(!context.get_current_sector().move_right()){
            context.next_sector(1,0);
        }
    }
    else if(str == "a"){
        if(!context.get_current_sector().move_left()){
            context.next_sector(-1,0);
        }
    }
    else if(str == "w"){
        if(!context.get_current_sector().move_up()){
            context.next_sector(0,-1);
        }
    }
    else if(str == "s"){
        if(!context.get_current_sector().move_down()){
            context.next_sector(0,1);
        }
    }else if(context.get_current_sector().next_to('@') && (str == "pick up" || str == "p")){
        if( context.get_current_sector().next_to('@')){
            pick_up_package(context);
        }

    } else if(str == "deliver" || str == "e"){
        auto pkg = context.get_current_package();
        if(!pkg.is_empty() && context.get_current_sector().next_to('@') && context.get_current_sector_x() == pkg.get_sector_x() && context.get_current_sector_y() == pkg.get_sector_y()){
            int difference_x = std::abs(pkg.get_planet_x() - context.get_current_sector().get_player_x());
            int difference_y = std::abs(pkg.get_planet_y() - context.get_current_sector().get_player_y());
            if(difference_x + difference_y <=1){
                player.add_win_point();
                context.set_current_package(Package());
            }
        }

    } else if(str == "view package" || str == "v"){
        cout << context.get_current_package();

    }else if(str == "do nothing" || str == "n"){

    }
    else if(str == "quit" || str == "q"){
        context.game_over();
    }

}