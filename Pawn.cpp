#include "Pawn.h"

#include <iostream>

Pawn::Pawn(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : ChessPiece(row, col, charPiece, blackOrWhite, isEmpty) {}

Pawn::~Pawn(){}

int Pawn::whichDiagonalEmpty(const char boardPieces_ [8][8])
{//Special function for pawn, as it can only move diagonally if there is an opponent piece there
    int returnInt = 0;
    int diagLeftCol = -1;
    int diagRightCol = -1;
    int diagRow = -1;
    if(getColour() == WHITE)
    {
        diagLeftCol = getCurrentLoc().getCol() - 1;
        diagRightCol = getCurrentLoc().getCol() + 1;
        diagRow = getCurrentLoc().getRow() - 1;
    }
    else if (getColour() == BLACK)
    {
        diagLeftCol = getCurrentLoc().getCol() - 1;
        diagRightCol = getCurrentLoc().getCol() + 1;
        diagRow = getCurrentLoc().getRow() + 1;
    }
    else
    {
        std::string errorMessage = "Error in Pawn function whichDiagonalEmpty, shouldnt have any other colour";
        throw errorMessage;
    }
    //Calculating left diagonal
    if(isWithinBoardLimit(diagRow, diagLeftCol))
    {
        if(boardPieces_[diagRow][diagLeftCol] == '-')
        {
            returnInt = returnInt + 1;
        }
        else
        {
            if(isBoardCharWhite(boardPieces_, diagRow, diagLeftCol) != getColour()) {}
            else
            {
                returnInt = returnInt + 1;
            }
        }
    }
    else
    {
        returnInt = returnInt + 1; //Adding to return value, to indicate the left diagonal is empty (shouldnt be considered as valid move)
    }
    if(isWithinBoardLimit(diagRow, diagRightCol))
    {
        if(boardPieces_[diagRow][diagRightCol] == '-')
        {
            returnInt = returnInt + 2;
        }
        else
        {
            if(isBoardCharWhite(boardPieces_, diagRow, diagRightCol) != getColour()) {}
            else
            {
                returnInt = returnInt + 2;
            }
            
        }
    }
    else
    {
        returnInt = returnInt + 2; //Adding to return value, to indicate the right diagonal is empty (shouldnt be considered as valid move)
    }
    return returnInt;
}

void Pawn::calPossiblePieceLoc(const char boardPieces_ [8][8], bool print)
{
    clearPossibleLoc();
    bool isFirstMove = false;
    int temptwoStepsRow = -1;
    int temptwoStepsCol = getCurrentLoc().getCol();
    int tempOneStepRow = -1;
    int tempOneStepCol = getCurrentLoc().getCol();
    if(getColour() == 1)
    {
        isFirstMove = (getCurrentLoc().getRow() == 6); //Check if it is a first move
        temptwoStepsRow = (getCurrentLoc().getRow() - 2);
        tempOneStepRow = (getCurrentLoc().getRow() - 1);
    }
    else if (getColour() == 0)
    {
        isFirstMove = (getCurrentLoc().getRow() == 1); //Check if it is a first move
        temptwoStepsRow = (getCurrentLoc().getRow() + 2);
        tempOneStepRow = (getCurrentLoc().getRow() + 1);
    }
    //Check if the requested end location is empty, as different moves depending on if it is or not
    if(isEmpty(boardPieces_, temptwoStepsRow, temptwoStepsCol) && isEmpty(boardPieces_, tempOneStepRow, tempOneStepCol) 
        && isWithinBoardLimit(temptwoStepsRow, temptwoStepsCol) && isFirstMove)
    {
        PieceLoc twoSteps;
        twoSteps.setRow(temptwoStepsRow);
        twoSteps.setCol(temptwoStepsCol);
        twoSteps.setIsEmpty(true);
        possiblePieceLoc_.emplace_back(twoSteps);
        if(print == true)
        {
            twoSteps.printInfo();
        }
    }
    if(isEmpty(boardPieces_, tempOneStepRow, tempOneStepCol) && isWithinBoardLimit(tempOneStepRow, tempOneStepCol))
    {
        PieceLoc oneStep;
        oneStep.setRow(tempOneStepRow);
        oneStep.setCol(tempOneStepCol);
        oneStep.setIsEmpty(true);
        possiblePieceLoc_.emplace_back(oneStep);
        if(print == true)
        {
            oneStep.printInfo();
        }
    }
    //Dealing with diagonal attack
    int diagonalReturnVal = whichDiagonalEmpty(boardPieces_);
    if(diagonalReturnVal < 3)
    {
        switch(diagonalReturnVal)
        {
            case 0:
            { //Can attack on both sides
                int tempDiagLeftStepCol = (getCurrentLoc().getCol() - 1);
                int tempDiagLeftStepRow = -1;
                int tempDiagRightStepCol = (getCurrentLoc().getCol() + 1);
                int tempDiagRightStepRow = -1;
                if(getColour() == WHITE)
                {
                    tempDiagLeftStepRow = (getCurrentLoc().getRow() - 1);
                    tempDiagRightStepRow = (getCurrentLoc().getRow() - 1);
                }
                else if (getColour() == BLACK)
                {
                    tempDiagLeftStepRow = (getCurrentLoc().getRow() + 1);
                    tempDiagRightStepRow = (getCurrentLoc().getRow() + 1);
                }
                if(isWithinBoardLimit(tempDiagLeftStepRow, tempDiagLeftStepCol))
                {
                    PieceLoc diagLeft;
                    diagLeft.setRow(tempDiagLeftStepRow);
                    diagLeft.setCol(tempDiagLeftStepCol);
                    diagLeft.setIsEmpty(false);
                    possiblePieceLoc_.emplace_back(diagLeft);
                    if(print == true)
                    {
                        diagLeft.printInfo();
                    }
                }
                if(isWithinBoardLimit(tempDiagRightStepRow, tempDiagRightStepCol))
                {
                    PieceLoc diagRight;
                    diagRight.setRow(tempDiagRightStepRow);
                    diagRight.setCol(tempDiagRightStepCol);
                    diagRight.setIsEmpty(false);
                    possiblePieceLoc_.emplace_back(diagRight);
                    if(print == true)
                    {
                        diagRight.printInfo();
                    }
                }
                break;
            }
            case 1:
            { //Only left empty, so can attack on right
                int tempDiagStepCol = (getCurrentLoc().getCol() + 1);
                int tempDiagStepRow = -1;
                if(getColour() == WHITE)
                {
                    tempDiagStepRow = (getCurrentLoc().getRow() - 1);
                }
                else if (getColour() == BLACK)
                {
                    tempDiagStepRow = (getCurrentLoc().getRow() + 1);
                }
                if(isWithinBoardLimit(tempDiagStepRow, tempDiagStepCol))
                {
                    PieceLoc diagRight;
                    diagRight.setRow(tempDiagStepRow);
                    diagRight.setCol(tempDiagStepCol);
                    diagRight.setIsEmpty(false);
                    possiblePieceLoc_.emplace_back(diagRight);
                    if(print == true)
                    {
                        diagRight.printInfo();
                    }
                }
                break;
            }
            case 2:
            { //Only right empty, so can attack on left
                int tempDiagStepCol = (getCurrentLoc().getCol() - 1);
                int tempDiagStepRow = -1;
                if(getColour() == WHITE)
                {
                    tempDiagStepRow = (getCurrentLoc().getRow() - 1);
                }
                else if (getColour() == BLACK)
                {
                    tempDiagStepRow = (getCurrentLoc().getRow() + 1);
                }
                if(isWithinBoardLimit(tempDiagStepRow, tempDiagStepCol))
                {
                    PieceLoc diagLeft;
                    diagLeft.setRow(tempDiagStepRow);
                    diagLeft.setCol(tempDiagStepCol);
                    diagLeft.setIsEmpty(false);
                    possiblePieceLoc_.emplace_back(diagLeft);
                    if(print == true)
                    {
                        diagLeft.printInfo();
                    }
                }
                break;
            }
            default:
                std::cerr << "Diagonal Return value returning unexpected value" << std::endl;
        }
    }
}