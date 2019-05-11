#ifndef __CONNECT4__
#define __CONNECT4__
#include<iostream>
#include<vector> 
#include<algorithm>
#include<chrono>
using namespace std;

#define AI 1 
#define Player 0;


class Board{
    public:
        vector<vector<int> >board(7,vector<int>(6));                   
        int turn;
    
    public:        
        int get_score();                                        //evalute the board 
        void display_board();                                   //print the board  
        int add_piece(int col);                                 //add piece to a column                            
        vector<Board> get_children();                           //get all possible moves from this state  
        bool win_state();
        bool is_terminal();
        


        

}; 


#endif

