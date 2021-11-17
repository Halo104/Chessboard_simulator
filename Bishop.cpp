#include "Bishop.h"

Bishop::Bishop(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece (row, col, charPiece, blackOrWhite, isEmpty) {}

Bishop::~Bishop(){}

void Bishop::calPossiblePieceLoc(const char boardPieces_ [8][8], bool print)
{
    clearPossibleLoc();
    int maxUp = getCurrentLoc().getRow();
    int maxDown = 7 - getCurrentLoc().getRow();
    int maxLeft = getCurrentLoc().getCol();
    int maxRight = 7 - getCurrentLoc().getCol();
    
    //Diagonal up left
    int diagUpLeftLimit = std::min(maxLeft, maxUp);
    for(int i = 1; i <= diagUpLeftLimit; i++){
        int diagUpLeftRow = getCurrentLoc().getRow() - i;
        int diagUpLeftCol = getCurrentLoc().getCol() - i ;
        if(isGeneralPosCalObstructed(diagUpLeftRow, diagUpLeftCol, "Diag up-left", "Bishop", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Diagonal up right
    int diagUpRightLimit = std::min(maxRight, maxUp);
    for(int i = 1; i <= diagUpRightLimit; i++){
        int diagUpRightRow = getCurrentLoc().getRow() - i;
        int diagUpRightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(diagUpRightRow, diagUpRightCol, "Diag up-right", "Bishop", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Diagonal down left
    int diagDownLeftLimit = std::min(maxLeft, maxDown);
    for(int i = 1; i <= diagDownLeftLimit; i++){
        int diagDownLeftRow = getCurrentLoc().getRow() + i;
        int diagDownLeftCol = getCurrentLoc().getCol() - i;
        if(isGeneralPosCalObstructed(diagDownLeftRow, diagDownLeftCol, "Diag down-left", "Bishop", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }

    //Diagonal down right
    int diagDownRightLimit = std::min(maxRight, maxDown);
    for(int i = 1; i <= diagDownRightLimit; i++){
        int diagDownRightRow = getCurrentLoc().getRow() + i;
        int diagDownRightCol = getCurrentLoc().getCol() + i;
        if(isGeneralPosCalObstructed(diagDownRightRow, diagDownRightCol, "Diag down-right", "Bishop", boardPieces_, print))
        {//stop looping whenever the direction moving is obstructed
            break;
        }
    }
}