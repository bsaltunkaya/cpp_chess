#ifndef CHESSHEAD_HPP
#define CHESSHEAD_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Piece{
    public:
    Piece(){pType='p';pColor=0;}
    Piece(char type,int color){pType=type;pColor=color;}
    char getType(){return pType;}
    int getColor(){return pColor;}
    private:
    char pType;//initials of each piece, expect n for knight
               //k reserved for king

    int pColor;//0 for black 1 for white 2 for empty
};


class Board{
    public: 
    Board();
    bool isValid(const string& move);
    void move(const string& move);
    void printBoard();
    friend class Piece;
    private:
    vector<vector<Piece> > pieceVector;
};


#endif