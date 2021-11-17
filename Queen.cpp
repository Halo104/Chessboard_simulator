#include "Queen.h"

Queen::Queen(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece(row, col, charPiece, blackOrWhite, isEmpty) {}

Queen::~Queen(){}

void Queen::calPossiblePieceLoc(const char boardPieces_[8][8], bool print)
{//Always 8 possible solutions, need to consider whether out of bound or contains friendly piece
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
        if(isGeneralPosCalObstructed(upRow, upCol, "Up", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Down
    for(int i = 1; i <= maxDown; i++)
    {
        int downRow = getCurrentLoc().getRow() + i;
        int downCol = getCurrentLoc().getCol();
        if(isGeneralPosCalObstructed(downRow, downCol, "Down", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Left
    for(int i = 1; i <= maxLeft; i++)
    {
        int leftRow = getCurrentLoc().getRow();
        int leftCol = getCurrentLoc().getCol() - i;
        if(isGeneralPosCalObstructed(leftRow, leftCol, "Left", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Right
    for(int i = 1; i <= maxRight; i++)
    {
        int rightRow = getCurrentLoc().getRow();
        int rightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(rightRow, rightCol, "Right", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }
    //DiagUpLeft
    int diagUpLeftLimit = std::min(maxLeft, maxUp);
    for(int i = 1; i <= diagUpLeftLimit; i++){
        int diagUpLeftRow = getCurrentLoc().getRow() - i;
        int diagUpLeftCol = getCurrentLoc().getCol() - i ;
        if(isGeneralPosCalObstructed(diagUpLeftRow, diagUpLeftCol, "Diag up-left", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }
    
    //DiagUpRight
    int diagUpRightLimit = std::min(maxRight, maxUp);
    for(int i = 1; i <= diagUpRightLimit; i++){
        int diagUpRightRow = getCurrentLoc().getRow() - i;
        int diagUpRightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(diagUpRightRow, diagUpRightCol, "Diag up-right", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //DiagDownLeft
    int diagDownLeftLimit = std::min(maxLeft, maxDown);
    for(int i = 1; i <= diagDownLeftLimit; i++){
        int diagDownLeftRow = getCurrentLoc().getRow() + i;
        int diagDownLeftCol = getCurrentLoc().getCol() - i;
        if(isGeneralPosCalObstructed(diagDownLeftRow, diagDownLeftCol, "Diag down-left", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //DiagDowRight
    int diagDownRightLimit = std::min(maxRight, maxDown);
    for(int i = 1; i <= diagDownRightLimit; i++){
        int diagDownRightRow = getCurrentLoc().getRow() + i;
        int diagDownRightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(diagDownRightRow, diagDownRightCol, "Diag down-right", "Queen", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }
}