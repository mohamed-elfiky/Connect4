#ifndef __CONNECT4__
#define __CONNECT4__
#include <iostream>
#include <vector> 
#include <algorithm>
#include <chrono>

using namespace std;

#define AI 1 
#define Player 0

typedef struct{
	int value;
	int col;
}val_col;

class Board{
    public:
        int col = 7 ;
        int row = 6 ;
        //intialize teh board.
        vector<vector<int> >game_board{{0,0,0,0,0,0,0,0},
                                       {0,0,0,0,0,0,0,0},
                                       {0,0,0,0,0,0,0,0},
                                       {0,0,0,0,0,0,0,0},
                                       {0,0,0,0,0,0,0,0},
                                       {0,0,0,0,0,0,0,0}};

       // int turn;
    public:

        //evalute the board
        int get_score();
        //print the board 
        void display_board();
        //add piece to a column  
        void add_piece(int col, int);                                                           
        vector<int> get_children();
        //get all possible moves from this state
        bool  win_state();
        bool is_terminal();
        bool is_valid(int);
        Board(const Board &);

}; 


#endif

