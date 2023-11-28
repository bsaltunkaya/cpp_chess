#include <iostream>
#include "chesshead.hpp"

int main(){
    Board mainboard;
    cout<<"Welcome.\n";
    mainboard.printBoard();
    string nextMove;
    cout<<"\nWhite plays first. Please enter move: ";
    cin>>nextMove;
    return 0;
}