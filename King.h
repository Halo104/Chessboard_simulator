#ifndef KING_H_
#define KING_H_

#include "ChessPieces.h"

class King : public ChessPiece
{

public:
    King(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~King(); //Using default empty destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);
};


#endif //KING_H_