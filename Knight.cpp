#include "Knight.h"

Knight::Knight(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece(row, col, charPiece, blackOrWhite, isEmpty) {}

Knight::~Knight(){}

void Knight::calPossiblePieceLoc(const char boardPieces_[8][8], bool print)
{//Always 8 possible solutions, need to consider whether out of bound or contains friend piece
    clearPossibleLoc();
    //Up-left
    int upLeftRow = getCurrentLoc().getRow() - 2;
    int upLeftCol = getCurrentLoc().getCol() - 1;
    generalPosCal(upLeftRow, upLeftCol, "Up-left", "Knight", boardPieces_, print);
    
    //Up-right
    int upRightRow = getCurrentLoc().getRow() - 2;
    int upRightCol = getCurrentLoc().getCol() + 1;
    generalPosCal(upRightRow, upRightCol, "Up-right", "Knight", boardPieces_, print);
    
    //Down-left
    int downLeftRow = getCurrentLoc().getRow() + 2;
    int downLeftCol = getCurrentLoc().getCol() - 1;
    generalPosCal(downLeftRow, downLeftCol, "Down-left", "Knight", boardPieces_, print);
    
    //Down-right
    int downRightRow = getCurrentLoc().getRow() + 2;
    int downRightCol = getCurrentLoc().getCol() + 1;
    generalPosCal(downRightRow, downRightCol, "Down-right", "Knight", boardPieces_, print);
    
    //lessUp-left
    int lessUpLeftRow = getCurrentLoc().getRow() - 1;
    int lessUpLeftCol = getCurrentLoc().getCol() - 2;
    generalPosCal(lessUpLeftRow, lessUpLeftCol, "lessUp-left", "Knight", boardPieces_, print);

    //lessUp-right
    int lessUpRightRow = getCurrentLoc().getRow() - 1;
    int lessUpRightCol = getCurrentLoc().getCol() + 2;
    generalPosCal(lessUpRightRow, lessUpRightCol, "lessUp-right", "Knight", boardPieces_, print);

    //lessDown-left
    int lessDownLeftRow = getCurrentLoc().getRow() + 1;
    int lessDownLeftCol = getCurrentLoc().getCol() - 2;
    generalPosCal(lessDownLeftRow, lessDownLeftCol, "lessDown-left", "Knight", boardPieces_, print);

    //lessDown-right
    int lessDownRightRow = getCurrentLoc().getRow() + 1;
    int lessDownRightCol = getCurrentLoc().getCol() + 2;
    generalPosCal(lessDownRightRow, lessDownRightCol, "lessDown-right", "Knight", boardPieces_, print);
}