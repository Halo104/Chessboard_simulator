#ifndef PAWN_H_
#define PAWN_H_

#include "ChessPieces.h"

class Pawn : public ChessPiece
{
private:
    //0 = non-empty, 1 = left empty, 2 = right empty, 3 = both empty
    int whichDiagonalEmpty(const char boardPieces_ [8][8]); 

public:
    Pawn(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~Pawn(); //Using default empty destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);
};


#endif //PAWN_H_