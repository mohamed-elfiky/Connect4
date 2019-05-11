#include "game.h"


 void game::get_player_move(){
    int col;
    cout<< "enter column:";
    cin >> col;
    while(!board.is_valid(col)){
        cout<<"invlaid move"<<endl;
        cout<< "enter column:";
        cin >> col;     
    }
    board.add_piece(col, Player);
}

void game::get_ai_move(){
    board.add_piece(1, AI);
}


void game::start_game(){

    
}