#include "board.h"
/*****************************************************************************************
                               ALL THE LOGIC OF AI WILL BE HERE 
******************************************************************************************/
class game{
    
    public:
    Board board ;
    int level = 0;
    
    
    /*AI*/
    public:
    game(){};
    val_col minmax(Board , int, int, int, int );
    int evaluate_move();
    

    
    
    /*Game*/
    public:
    //contains the game loop
    void start_game();               
    void get_player_move();
    void get_ai_move();
    // Useless
    bool game_over();

};










