#include "board.h"



void Board::display_board(){
    for(int i = 5 ; i >=0 ; i--){
        for(int j = 0 ; j < 7 ; j++){
            
            cout<<this->game_board[j][j]<<" ";
        }
        cout<<endl;
    }
}



bool Board::is_valid(int col){
    if(col > 6) return false ;
    if(this->game_board[5][col] != 0) return true;    
    
}


void Board::add_piece(int col, int player){
    
    for(int i = 0 ; i< 6 ; i++){
        if(this->game_board[i][col]==0){
            if(player == AI){
                this->game_board[i][col]=1;
            }
            else{
                this->game_board[i][col]=2;
            }
            break;
        }
    }    
}


int Board::win_state(){
    // check horizontal
    for(int i = 0 ; i < row ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < col-1 ; j++){
             if(this->game_board[i][j]!=this->game_board[i][j+1]){count = 0 ;}
             count ++ ;
        }
        if(count == 4) return AI;
        else if(count == 8) return Player;    
    }
    // check vertical 
    for(int i = 0 ; i < col ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < row-1 ; j++){
             if(this->game_board[i][j]!=this->game_board[i][j+1]){count = 0 ;}
             count ++ ;
        }
        if(count == 4) return AI;
        else if(count == 8) return Player;    
    }
    // check diagonally
    
    
    
    return -1;
}





































