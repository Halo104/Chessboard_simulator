#ifndef QUEEN_H_
#define QUEEN_H_

#include "ChessPieces.h"

class Queen : public ChessPiece
{

public: 
    Queen(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~Queen(); //Using default empty destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);
};

#endif //QUEEN_H_