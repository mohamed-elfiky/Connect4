#include "board.h"
/*****************************************************************************************
                               ALL THE LOGIC OF AI WILL BE HERE 
******************************************************************************************/
class game{
    
    public:
    Board board ;
    
    
    
    /*AI*/
    public:
    game(){};
    val_col minmax(Board , int, int, int, int );
    
    

    
    
    /*Game*/
    public:
    //contains the game loop
    void start_game();               
    void get_player_move();
    void get_ai_move();
    // Useless
    bool game_over();

};










