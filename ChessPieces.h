#ifndef CHESSPIECES_H_
#define CHESSPIECES_H_

#include "PieceLoc.h"
#include "utils.h"

#include <vector>

class ChessPiece
{
    PieceLoc currentPos_;
    char charPiece_;
    bool blackOrWhite_; //0 for black, 1 for white
    bool inPlay_;
    
public:
    std::vector<PieceLoc> possiblePieceLoc_;

    ChessPiece(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty);
    virtual ~ChessPiece(); //Default virtual destructor

    void setStartPos (int row, int col);
    void setStartPos (const PieceLoc &InputPieceLoc);
    void setCharPiece(char charPiece);
    void setPieceColour (bool colour);
    void setInPlay(bool inPlay);

    PieceLoc& getCurrentLoc();
    char getCharPiece();
    int getSizePossibleLoc();
    PieceLoc& getPossibleLoc(int i);
    bool getColour(); //0 for black, 1 for white
    bool getInPlay();

    void clearPossibleLoc();
    void generalPosCal(int row, int col, std::string position, std::string piece, const char boardPieces_ [8][8], bool print);
    bool isGeneralPosCalObstructed(int row, int col, std::string position, std::string piece, const char boardPieces_ [8][8], bool print);

    virtual void calPossiblePieceLoc(const char boardPieces_ [8][8], bool print) = 0; //Pure virtual function
};

#endif //CHESSPIECES_B_