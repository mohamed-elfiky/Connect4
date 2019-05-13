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
	int best_move =  this->evaluate_move();
    board.add_piece(best_move, AI);
}


// game loop.
void game::start_game(){
    while(true){

    	if(this->board.get_children().size()>0)
    	{
    	this->get_ai_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state(AI)){cout<<"ai_wins";break;}}
    	else{
    		cout<<"draw!";break;
    	}


        if(this->board.get_children().size()>0){
        this->get_player_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state(Player)){cout<<"player wins";break;}
        }
        else
        {cout<<"draw";break;}


    }

}


int game::evaluate_move(){
	int alpha =std::numeric_limits<int>::min();
	int beta=std::numeric_limits<int>::max();
	vector<int>states = this->board.get_children();

	for(int step:states){
		bool win = false;
		Board new_state(this->board);
		new_state.add_piece(step,AI);
		if(new_state.win_state(AI))win=true;
		if (win) return step;
	}
	for(int step:states){
		bool win = false;
		Board new_state(this->board);
		new_state.add_piece(step,Player);
		if(new_state.win_state(Player))win=true;
	    if (win) return step;
	}

	int depth = 7;
	int best_move = states[0];
	for(int i : states ){
		if(alpha>=beta){
			return best_move;
		}

		Board new_state(this->board);
		new_state.add_piece(i,AI);
		int score = minmax(new_state, depth ,alpha, beta,Player);
		if(score>alpha){
			best_move = i;
			alpha = score;
	}
}
return best_move;
}
int game::minmax(Board current_state, int depth, int alpha, int beta, int max_player){

	if (current_state.is_terminal()){
		if(current_state.win_state(AI) && max_player == AI ){

			return std::numeric_limits<int>::min();
		}
		else if(current_state.win_state(Player) && max_player == Player )
			{

				return std::numeric_limits<int>::max();}

		else{
			return 0;
		}
	}
	if (depth == 0){
		//cout << "at depth\n";
		//current_state.display_board();
		return current_state.get_score();
	}

	vector<int>possible_states = current_state.get_children();

	if(max_player == AI){
		int value = numeric_limits<int>::min();
		for(int col: possible_states){
			Board new_state(current_state);
			new_state.add_piece(col,AI);
			int ai_score = minmax(new_state, depth-1, alpha, beta, Player);
			if(ai_score > value ){
				value = ai_score;
			}
		alpha = max(alpha, value);
		if (alpha >= beta)
			break;
		}
		return value;
	}
	else{
		int value = numeric_limits<int>::max();

				for(int col: possible_states){
					Board new_state(current_state);
					new_state.add_piece(col,Player);
					int ai_score = minmax(new_state, depth-1, alpha, beta, AI);
					if(ai_score < value ){
						value = ai_score;
					}
				beta = min(beta, value);
				if (alpha >= beta)
					break;
				}
				return value;

	}

}












