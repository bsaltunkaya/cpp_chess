#include <iostream>
#include "chesshead.hpp"

using namespace std;

Board::Board(){
    //init vector
    pieceVector.resize(8);
        for (int i=0;i<8;i++){
            pieceVector[i].resize(8);
        }
        
        //insert blanks  first
        for(int i=9;i<48;i++){
        pieceVector[i/8][i%8]=Piece('.',2);
    }
    //insert black non pawn pieces
    pieceVector[0][0] = Piece('r', 0);
    pieceVector[0][1] = Piece('n', 0);
    pieceVector[0][2] = Piece('b', 0);
    pieceVector[0][3] = Piece('q', 0);
    pieceVector[0][4] = Piece('k', 0);
    pieceVector[0][5] = Piece('b', 0); 
    pieceVector[0][6] = Piece('n', 0); 
    pieceVector[0][7] = Piece('r', 0);

    //insert black pawns
    for(int i=0;i<8;i++){
        pieceVector[1][i]=Piece('p',0);
    }

    //insert white non pawn pieces
    pieceVector[7][0] = Piece('R', 1);
    pieceVector[7][1] = Piece('N', 1);
    pieceVector[7][2] = Piece('B', 1);
    pieceVector[7][3] = Piece('Q', 1);
    pieceVector[7][4] = Piece('K', 1);
    pieceVector[7][5] = Piece('B', 1); 
    pieceVector[7][6] = Piece('N', 1); 
    pieceVector[7][7] = Piece('R', 1);

    //insert white pawns
    for(int i=0;i<8;i++){
    pieceVector[6][i]=Piece('P',1);
    }

}

void Board::printBoard(){
            static int file=8;
    cout<<"\n";//using endl is non desirable,
               //flushes output buffer.
    for(int i=0;i<64;i++){//nested for loop is too taxing on the cpu so
                          //will use division tricks
        if((i)%8==0){
            cout<<"\n";
        }
        
        if((i)%8==0){
            cout<<file<<" | ";
            file--;
        }
        cout<<pieceVector[i/8][i%8].getType()<<" ";
    }
    cout<<"\n    ---------------\n";
    cout<<"    a b c d e f g h\n";
    file=8;
}