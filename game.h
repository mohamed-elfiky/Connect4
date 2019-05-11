#include "board.h"

class game{
    
    public:
    Board board ;
    
    
    
    /*AI*/
    public:
    game(){};
    int minmax();
    
    

    
    
    /*Game*/
    public:
    void start_game();               //contains the game loop
    void get_player_move();
    void get_ai_move();
    bool game_over();

};










