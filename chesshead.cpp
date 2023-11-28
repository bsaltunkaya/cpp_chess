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

bool Board::isValid(const string& move){
    int len=move.length();
    int movecord;

    

    if(len=2){//pawn move
        int addForRank;
        switch(move[0]){
            case 'a':addForRank=0;
            case 'b':addForRank=1;
            case 'c':addForRank=2;
            case 'd':addForRank=3;
            case 'e':addForRank=4;
            case 'f':addForRank=5;
            case 'g':addForRank=6;
            case 'h':addForRank=7;
        }
        movecord=(8-static_cast<int>(move[1]))*8+addForRank;
        if(movecount%2==0){//white's turn
            if(pieceVector[movecord/8][movecord%8].getColor()==1){//teammate present
                return false;
            }
            if(pieceVector[movecord/8][movecord%8].getColor()==0){//enemy present
                return false;
            }
            if(move[1]==4){
                
            }
           // if()
        }
        else{//black's turn
            if(pieceVector[movecord/8][movecord%8].getColor()==0){//teammate present
                return false;
            }
            if(pieceVector[movecord/8][movecord%8].getColor()==1){//enemy present
                return false;
            }
        }


    }

}