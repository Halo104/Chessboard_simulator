#include "King.h"

King::King(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece(row, col, charPiece, blackOrWhite, isEmpty) {}

King::~King(){}

void King::calPossiblePieceLoc(const char boardPieces_[8][8], bool print)
{//Always 8 possible solutions, need to consider whether out of bound or contains friend piece
    clearPossibleLoc();
    //Up
    int upRow = getCurrentLoc().getRow() - 1;
    int upCol = getCurrentLoc().getCol();
    generalPosCal(upRow, upCol, "Up", "King", boardPieces_, print);

    //Down
    int downRow = getCurrentLoc().getRow() + 1;
    int downCol = getCurrentLoc().getCol();
    generalPosCal(downRow, downCol, "Down", "King", boardPieces_, print);

    //Left
    int leftRow = getCurrentLoc().getRow();
    int leftCol = getCurrentLoc().getCol() - 1;
    generalPosCal(leftRow, leftCol, "Left", "King", boardPieces_, print);

    //Right
    int rightRow = getCurrentLoc().getRow();
    int rightCol = getCurrentLoc().getCol() + 1;
    generalPosCal(rightRow, rightCol, "Right", "King", boardPieces_, print);

    //DiagUpLeft
    int DiagUpLeftRow = getCurrentLoc().getRow() - 1;
    int DiagUpLeftCol = getCurrentLoc().getCol() - 1;
    generalPosCal(DiagUpLeftRow, DiagUpLeftCol, "Diag Up-Left", "King", boardPieces_, print);

    //DiagUpRight
    int DiagUpRightRow = getCurrentLoc().getRow() - 1;
    int DiagUpRightCol = getCurrentLoc().getCol() + 1;
    generalPosCal(DiagUpRightRow, DiagUpRightCol, "Diag Up-Right", "King", boardPieces_, print);

    //DiagDownLeft
    int DiagDownLeftRow = getCurrentLoc().getRow() + 1;
    int DiagDownLeftCol = getCurrentLoc().getCol() - 1;
    generalPosCal(DiagDownLeftRow, DiagDownLeftCol, "Diag Down-Left", "King", boardPieces_, print);

    //DiagDowRight
    int DiagDownRightRow = getCurrentLoc().getRow() + 1;
    int DiagDownRightCol = getCurrentLoc().getCol() + 1;
    generalPosCal(DiagDownRightRow, DiagDownRightCol, "Diag Down-Right", "King", boardPieces_, print);
}
