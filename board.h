#ifndef __CONNECT4__
#define __CONNECT4__
#include <iostream>
#include <vector> 
#include <algorithm>
#include <chrono>
#include <limits>
using namespace std;

#define AI 1 
#define Player 2

typedef struct{
	int value;
	int col;
}val_col;
/*
 *
 *
1 0 0 0 0 0 0
1 0 0 0 0 0 0
2 0 0 0 0 0 0
1 0 0 0 2 0 0
2 1 0 0 2 0 0
1 1 0 0 2 0 0
 *
 *
 * */



class Board{
    public:
        int col = 7 ;
        int row = 6 ;
        //intialize teh board.
        vector<vector<int> >game_board{{1,2,3,2,2,1,1},
                                       {2,3,2,1,2,1,2},
                                       {1,2,3,4,4,2,1},
                                       {2,1,2,1,3,0,2},
                                       {1,3,4,3,2,3,1},
                                       {3,0,0,3,1,2,1}};

       // int turn;
    public:
        Board(){};
        //evalute the board
        int get_score();
        //print the board 
        void display_board();
        //add piece to a column  
        void add_piece(int col, int);                                                           
        vector<int> get_children();
        //get all possible moves from this state
        bool  win_state(int );
        bool is_terminal();
        bool is_valid(int);
        Board(const Board &);

}; 


#endif

