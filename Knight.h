#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "ChessPieces.h"

class Knight : public ChessPiece
{

public:
    Knight(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~Knight(); //Using default empty destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);
};

#endif //KNIGHT_H_