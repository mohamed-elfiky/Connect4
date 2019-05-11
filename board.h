#ifndef __CONNECT4__
#define __CONNECT4__
#include <iostream>
#include <vector> 
#include <algorithm>
#include <chrono>

using namespace std;

#define AI 1 
#define Player 0
 
class Board{
    public:
        int col = 7 ;
        int row = 6 ;
        vector<vector<int> >game_board{{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

    public:
        int get_score();                                        //evalute the board 
        void display_board();                                   //print the board  
        void add_piece(int col, int);                                 //add piece to a column                            
        vector<Board> get_children();                           //get all possible moves from this state  
        bool  win_state();
        bool is_terminal();
        bool is_valid(int);
        


}; 


#endif

