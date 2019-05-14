#include "board.h"



void Board::display_board(){
    for(int i = row-1 ; i >=0 ; i--){
        for(int j = 0 ; j < col ; j++){
            
            cout<<this->game_board[i][j]<<" ";
        }
        cout<<endl;
    }
}

//checking if the input is valid.
bool Board::is_valid(int col){
    // if the input column >6 returun false.
    if(col > 6) return false ;
    //if the col is full return false.
    if(this->game_board[5][col] != 0) return false;
    return true;
    


}

// add pice to our board.
void Board::add_piece(int col, int player){
    
    for(int i = 0 ; i< 6 ; i++){
        if(this->game_board[i][col]==0){
            if(player == AI){
                //one for AI.
                this->game_board[i][col]=1;
            }
            else{
                //two for human.
                this->game_board[i][col]=2;
            }
            break;
        }
    }    
}



bool Board::is_terminal(){
	if(this->win_state() || this->win_state() || (this->get_children()).size()==0)
		return true;

	return false;
}


vector<int>Board::get_children(){
	vector<int>valid_locs;
	for(int i = 0 ; i< col ; i++){
		if(is_valid(i)){
			valid_locs.push_back(i);
		}
	}
	return valid_locs;
}


Board::Board(const Board & board){
	col = board.col;
	row = board.row;
	for(int i = 0 ; i < row ; i++){
		for(int j= 0 ; j < col ;j++ ){
			game_board[i][j] = board.game_board[i][j];
		}
	}
}



int Board::get_score( ){

  int result = 0;
    //check horizontally
    for(int i=0; i<row; i++)
        for(int j=0; j<=col-4; j++){
            if(this->game_board[i][j]== AI && this->game_board[i][j+1]== AI && this->game_board[i][j+2]== AI && this->game_board[i][j+3]== AI)
                result+=100;

            //else if(this->game_board[i][j]== AI && this->game_board[i][j+1]== AI && this->game_board[i][j+2]== AI)
            	//result+=20;

            else if(this->game_board[i][j]== AI && this->game_board[i][j+1]== AI)
                result = result+10;
            if(this->game_board[i][j]== Player && this->game_board[i][j+1]== Player && this->game_board[i][j+2]== Player && this->game_board[i][j+3]== Player)
                result-=100;

            else if(this->game_board[i][j]== Player && this->game_board[i][j+1]== Player && this->game_board[i][j+2]== Player)
                result-=50;

           // else if(this->game_board[i][j]== Player && this->game_board[i][j+1]== Player)
                //result = result-20;
        }
    //check verticals
    for(int i=0; i<=row-4; i++)
        for(int j=0; j<col; j++){
        	if(this->game_board[i][j]== AI && this->game_board[i+1][j]== AI && this->game_board[i+2][j]== AI && this->game_board[i][j+3]== 1)
        	     result+=100;
        	//else if(this->game_board[i][j]== AI && this->game_board[i+1][j]== AI && this->game_board[i+1][j]== AI)
        	     //result+=20;
        	else if(this->game_board[i+1][j]== AI && this->game_board[i+1][j]== AI)
        	     result = result+10;
        	if(this->game_board[i][j]==Player && this->game_board[i+1][j]==Player && this->game_board[i+2][j]==Player&& this->game_board[i+3][j]==Player)
        	     result-=100;
        	else if(this->game_board[i][j]==Player && this->game_board[i+1][j]==Player && this->game_board[i+2][j]==Player)
        	     result-=50;
            //else if(this->game_board[i][j]==Player && this->game_board[i+1][j]== 2)
        	     //result = result-20;

        }

    return result;

}

// check if state is win state.
bool Board::win_state(){
    // check horizontal
    for(int i = 0 ; i< col-3  ; i++)
    	for(int j = 0 ; j < row  ; j++ ){
    		if(
    		   this->game_board[i][j]==
    		   this->game_board[i][j+1]
									 &&
			   this->game_board[i][j+1]
									 ==
			   this->game_board[i][j+2]
									 &&
			   this->game_board[i][j+2]==
			   this->game_board[i][j+3]
									 &&
			   this->game_board[i][j+3]!=0
									 )
    			return true;
    	}
    // check vertical
    for(int i = 0 ; i< row-3  ; i++)
    	for(int j = 0 ; j < col  ; j++ ){
    		if(
    		   this->game_board[i][j]==
    		   this->game_board[i+1][j]
									 &&
			   this->game_board[i+1][j]
									 ==
			   this->game_board[i+2][j]
									 &&
			   this->game_board[i+2][j]==
			   this->game_board[i+3][j]
									 &&
			   this->game_board[i+3][j]!=0
									 )
    			return true;
    	}
    // check diagonal downwards
    for(int j = 0 ; j< col -3 ; j++)
    	for(int i = 3 ; i < row  ; i++ ){
    		if(
    		   this->game_board[i][j]==
    		   this->game_board[i-1][j+1]
									 &&
			   this->game_board[i-1][j+1]
									 ==
			   this->game_board[i-2][j+2]
									 &&
			   this->game_board[i-2][j+2]==
			   this->game_board[i-3][j+3]
									 &&
			   this->game_board[i-3][j+3]!=0
									 )
    			return true;
    	}

    // check diagonal upwards
    for(int j = 0 ; j< col -3 ; j++)
    	for(int i = 0 ; i < row -3  ; i++ ){
    		if(
    		   this->game_board[i][j]==
    		   this->game_board[i+1][j+1]
									 &&
			   this->game_board[i+1][j+1]
									 ==
			   this->game_board[i+2][j+2]
									 &&
			   this->game_board[i+2][j+2]==
			   this->game_board[i+3][j+3]
									 &&
			   this->game_board[i+3][j+3]!=0
									 )
    			return true;
    		}
    return false;
}













