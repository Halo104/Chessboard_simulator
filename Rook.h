#ifndef ROOK_H_
#define ROOK_H_

#include "ChessPieces.h"

class Rook : public ChessPiece
{

public:
    Rook(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~Rook(); //Default destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);
};


#endif //ROOK_H_