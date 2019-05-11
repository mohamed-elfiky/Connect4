
#include "connect4.h"

void get_player_move(vector<vector<int> >&board){
    int col;
    bool valid = false;
    cout << "please enter your move: "<<endl;
    cin >> col;
    while(valid == false){
        if(board[col].size() >= 6){
            cout<<"column is full, enter new value: " << endl;
            cin >> col;
            valid = false;
        } 
        else{
            valid = true;
        }
    board[col].push_back(2);
}


void display(vector<vector<int> >&board){
    for(int i = 5 ; i >=0 ; i--){
        for(int j = 0 ; j < 7 ; j++){
            
            cout<<board[j][j]<<" ";
        }
        cout<<endl;
    }
}