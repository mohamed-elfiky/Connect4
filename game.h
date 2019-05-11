#include "connect4.h"

class game{
    
    public:
    Board board ;
    
    
    
    /*AI*/
    public:
    int minmax();
    
    

    
    
    /*Game*/
    public:
    void satrt_game();               //contains the game loop
    void get_player_move();
    void get_ai_move();

};










