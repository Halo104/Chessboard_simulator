#ifndef BISHOP_H_
#define BISHOP_H_

#include "ChessPieces.h"

class Bishop : public ChessPiece
{
private:

public:
    Bishop(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    ~Bishop(); //Using default empty destructor
    void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print);

};


#endif //BISHOP_H_