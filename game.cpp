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
	vector<int>vec = this->board.get_children();
	int move = -1;
	for(int i : vec){  //check to block 3
		Board checking_state(this->board);
		checking_state.add_piece(i, Player);
		if(checking_state.win_state()){
			move = i ;
		}

	}
	for(int i : vec){  //check to win 3
		Board checking_state(this->board);
		checking_state.add_piece(i, AI);
		if(checking_state.win_state()){
			move = i ;
		}

	}

	if(move == -1)
		move =  this->minmax(this->board,this->level, numeric_limits<int>::min(), numeric_limits<int>::max(), AI).col;
    board.add_piece(move, AI);
}


// game loop.
void game::start_game(){



int turn, glevel  ;
cout << "choose level easy(1) ,medium(2) ,hard(3)";
cin >> glevel;
switch(glevel){
	case 1 : this->level = 4;break;
	case 2 : this->level = 8;break;
	case 3 : this->level = 10;break;
}
cout<<"enter 1 for starting first or 2 to start second "<<endl;
cin >> turn;

if(turn == 2){
	while(true){

    	if(this->board.get_children().size()>0)
    	{
    	this->get_ai_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state()){cout<<"ai_wins";break;}}
    	else{
    		cout<<"draw!";break;
    	}


        if(this->board.get_children().size()>0){
        this->get_player_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state()){cout<<"player wins";break;}
        }
        else
        {cout<<"draw";break;}


    }
}

if(turn == 1){
	this->board.display_board();
	while(true){



        if(this->board.get_children().size()>0){
        this->get_player_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state()){cout<<"player wins";break;}
        }
        else
        {cout<<"draw";break;}


		if(this->board.get_children().size()>0)
    	{
    	this->get_ai_move();
        this->board.display_board();
        cout<<"-----------------------------------------"<<endl;
        if(this->board.win_state()){cout<<"ai_wins";break;}}
    	else{
    		cout<<"draw!";break;
    	}





    }
}



}


val_col game::minmax(Board current_state, int depth, int alpha, int beta, int max_player){

	if (current_state.is_terminal()){
		if(current_state.win_state() && max_player == Player){

			return { numeric_limits<int>::max(),0 };
		}
		else if(current_state.win_state() && max_player == AI)
			{

			return { numeric_limits<int>::min(),0};
		}

		else{
			return { 0,0};
		}
	}
	if (depth == 0){
		//cout << "at depth\n";
		//current_state.display_board();
		return { current_state.get_score(),3 };
	}

	vector<int>possible_states = current_state.get_children();

	if(max_player == AI){
		int value = numeric_limits<int>::min();
		int temp_col=0;
		for(int col: possible_states){
			Board new_state(current_state);
			new_state.add_piece(col,AI);
			val_col ai_score =minmax(new_state, depth-1, alpha, beta, Player);
			if(ai_score.value > value ){
				//value = ai_score;
				value = ai_score.value;
				temp_col = col;
			}
		alpha = max(alpha, value);
		if (alpha >= beta)
			break;
		}
		//cout << temp_col<<"\n";
		return { value, temp_col };
	}
	else{
		int value = numeric_limits<int>::max();
		int temp_col=1;
				for(int col: possible_states){
					Board new_state(current_state);
					new_state.add_piece(col,Player);
					val_col ai_score = minmax(new_state, depth-1, alpha, beta, AI);
					if(ai_score.value < value ){
						value = ai_score.value;
						temp_col = col;
					}
				beta = min(beta, value);
				if (alpha >= beta)
					break;
				}
				//return value;
				//cout << temp_col<<"\n";
				return { value, temp_col };
	}

}












