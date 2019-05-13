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

// check if state is win state.
bool Board::win_state(){
    // check horizontal
    for(int i = 0 ; i < row ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < col-1 ; j++){
             // check the current cell and the next cell.
             if(this->game_board[i][j]!=this->game_board[i][j+1]){count = 0 ;}
             count+=this->game_board[i][j] ;
             //3 not 4 ---> we did not add the last cell.
             if(count == 3) return true;
             else if(count == 6) return true;
        }
        //if(count == 3) return true;
        //else if(count == 6) return true;
    }
    // check vertical 
    for(int i = 0 ; i < col ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < row-1 ; j++){
             if(this->game_board[j][i]!=this->game_board[j+1][i]){count = 0 ;}
             count+=this->game_board[j][i] ;
             if(count == 3) return true;
             else if(count == 6) return true;
        }
       // if(count == 3) return true;
       // else if(count == 6) return true;
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











int Board::get_score( ){
	int score = 0 ;

	// check horizontal
    for(int i = 0 ; i < row ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < col-1 ; j++){
             // check the current cell and the next cell.
             if(this->game_board[i][j]!=this->game_board[i][j+1]){count = 0 ;}
             count+=this->game_board[i][j] ;
             //3 not 4 ---> we did not add the last cell.
             if(count == 3) score += 100;
             else if(count==2) score +=5;
             else if(count == 1) score +=2;
             //else if(count == 6)  score -=100;
             else if(count == 4) score -=5 ;
        }



    }

    // check vertically
        for(int i = 0 ; i < col ; i++ ){
            int count = 0 ;
            for(int j = 0 ; j < row-1 ; j++){
                 if(this->game_board[j][i]!=this->game_board[j+1][i]){count = 0 ;}
                 count+=this->game_board[j][i] ;
                 //3 not 4 ---> we did not add the last cell.
                 if(count == 3) score += 100;
                 else if(count==2) score +=5;
                 else if(count == 1) score +=2;
                 //else if(count == 6)  score -=100;
                 else if(count == 4) score -=5 ;
            }
           // if(count == 3) return true;
           // else if(count == 6) return true;
        }

    // check diagonally


    return score;

}



bool Board::is_terminal(){
	if(this->win_state()  || (this->get_children()).size()>0)
		return true;

	return false;
}


vector<int>Board::get_children(){
	vector<int>valid_locs;
	for(int i = 0 ; i< col ; i++){
		if(is_valid(col)){
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




























