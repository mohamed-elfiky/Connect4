#include "game.h"
/*****************************************************************************************
                               ALL THE LOGIC OF AI WILL BE HERE 
******************************************************************************************/
 // getting input from humman player. 
 void game::get_player_move(){
    int col;
    cout<< "enter column:";
    cin >> col;
  // check if the input is valid.
    while(!board.is_valid(col)){
        cout<<"invlaid move"<<endl;
        cout<< "enter column:";
        cin >> col;     
    }
    board.add_piece(col, Player);
}

void game::get_ai_move(){
    // to be implemented
    board.add_piece(1, AI);
}


// game loop.
void game::start_game(){
    while(true){
        //this->get_ai_move();
        //if(false){cout<<"ai_wins";break;}

        this->board.display_board();

        this->get_player_move();

        this->board.display_board();

        if(this->board.win_state()){cout<<"player wins";break;}
        

    }

}




val_col game::minmax(Board current_state, int depth, int alpha, int beta, int max_player){

	if (current_state.is_terminal())
		if(current_state.win_state() && max_player == AI ){
			return {NULL,1000000000};
		}
		else if(current_state.win_state() && max_player == Player )
			return {NULL,-1000000000};
		else{
			return {NULL, 0};
		}
	else if (depth == 0){
		return {NULL, current_state.get_score()};
	}

	vector<int>possible_states = current_state.get_children();

	if(max_player == AI){
		int value = -10000000000;
		int col;
		for(int col: possible_states){
			Board new_state(current_state);
			new_state.add_piece(col,AI);
			val_col ai_score = minmax(new_state, depth-1, alpha, beta, max_player);
			if(ai_score.value < value ){
				value = ai_score.value;
				col = ai_score.col;
			}
		beta = min(beta, value);
		if (alpha >= beta)
			break;
		}
		return {value, col};
	}

	return 0;
}












