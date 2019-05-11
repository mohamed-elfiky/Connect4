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
    while(true){
        //this->get_ai_move();
        //if(false){cout<<"ai_wins";break;}

        this->board.display_board();

        this->get_player_move();

        this->board.display_board();

        //if(this->board.win_state()){cout<<"player wins";break;}
        

    }

}
