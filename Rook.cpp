#include "Rook.h"

Rook::Rook(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece(row, col, charPiece, blackOrWhite, isEmpty) {}

Rook::~Rook(){}

void Rook::calPossiblePieceLoc(const char boardPieces_[8][8], bool print)
{
    clearPossibleLoc();
    int maxUp = getCurrentLoc().getRow();
    int maxDown = 7 - getCurrentLoc().getRow();
    int maxLeft = getCurrentLoc().getCol();
    int maxRight = 7 - getCurrentLoc().getCol();
    //Up
    for(int i = 1; i <= maxUp; i++)
    {
        int upRow = getCurrentLoc().getRow() - i;
        int upCol = getCurrentLoc().getCol();
        if(isGeneralPosCalObstructed(upRow, upCol, "Up", "Rook", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Down
    for(int i = 1; i <= maxDown; i++)
    {
        int downRow = getCurrentLoc().getRow() + i;
        int downCol = getCurrentLoc().getCol();
        if(isGeneralPosCalObstructed(downRow, downCol, "Down", "Rook", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Left
    for(int i = 1; i <= maxLeft; i++)
    {
        int leftRow = getCurrentLoc().getRow();
        int leftCol = getCurrentLoc().getCol() - i;
        if(isGeneralPosCalObstructed(leftRow, leftCol, "Left", "Rook", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Right
    for(int i = 1; i <= maxRight; i++)
    {
        int rightRow = getCurrentLoc().getRow();
        int rightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(rightRow, rightCol, "Right", "Rook", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }
}