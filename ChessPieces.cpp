#include "ChessPieces.h"
#include "PieceLoc.h"
#include "utils.h"

#include <algorithm>
#include <iostream>
#include <vector>

ChessPiece::ChessPiece(int row, int col, char charPiece, bool blackOrWhite, bool isEmpty) : charPiece_(charPiece), blackOrWhite_(blackOrWhite)
{
    currentPos_.setRow(row);
    currentPos_.setCol(col);
    currentPos_.setIsEmpty(isEmpty);
    inPlay_ = true;
}

ChessPiece::~ChessPiece(){}

void ChessPiece::setStartPos(int row, int col)
{
    currentPos_.setRow(row);
    currentPos_.setCol(col);
}
void ChessPiece::setStartPos(const PieceLoc &InputPieceLoc)
{
    currentPos_.setRow(InputPieceLoc.getRow());
    currentPos_.setCol(InputPieceLoc.getCol());
}
void ChessPiece::setCharPiece(char charPiece)
{
    charPiece_ = charPiece;
}
void ChessPiece::setPieceColour (bool colour)
{
    blackOrWhite_ = colour;
}
void ChessPiece::setInPlay(bool inPlay)
{
    inPlay_ = inPlay;
}

PieceLoc& ChessPiece::getCurrentLoc()
{
    return currentPos_;
}
char ChessPiece::getCharPiece()
{
    return charPiece_;
}
int ChessPiece::getSizePossibleLoc()
{
    return possiblePieceLoc_.size();
}
PieceLoc& ChessPiece::getPossibleLoc(int i)
{
    return possiblePieceLoc_[i];
}
bool ChessPiece::getColour()
{
    return blackOrWhite_;
}
bool ChessPiece::getInPlay()
{
    return inPlay_;
}

void ChessPiece::clearPossibleLoc()
{//clearing vector for new values
    possiblePieceLoc_.clear(); 
}

void ChessPiece::generalPosCal(int row, int col, std::string position, std::string piece, const char boardPieces_ [8][8], bool print)
{//Used as a generic function to calculate if a piece can move into a position, 
 //checks if the position is within limits, then if it is empty, if not empty, checks if it is an opponents piece at the location
    if(isWithinBoardLimit(row, col))
    {
        if(isEmpty(boardPieces_, row, col))
        {
            PieceLoc tempLoc;
            tempLoc.setRow(row);
            tempLoc.setCol(col);
            tempLoc.setIsEmpty(true);
            possiblePieceLoc_.emplace_back(tempLoc);
            if(print == true)
            {
                tempLoc.printInfo();
            }
        }
        else
        { //Colour check only if the location isn't empty
            if(isBoardCharWhite(boardPieces_, row, col) != getColour())
            {
                PieceLoc tempLoc;
                tempLoc.setRow(row);
                tempLoc.setCol(col);
                tempLoc.setIsEmpty(false);
                possiblePieceLoc_.emplace_back(tempLoc);
                if(print == true)
                {
                    tempLoc.printInfo();
                }
            }
            else
            {
                if(print == true)
                {
                    std::cout << position << " pos in " << piece << " is of same colour" << std::endl;
                }
            }
        }
        
    }
    else
    {
        if(print == true)
        {
            std::cout << position << " pos in " << piece << " is out of bound" << std::endl;
        }
    }
}

bool ChessPiece::isGeneralPosCalObstructed(int row, int col, std::string position, std::string piece, const char boardPieces_ [8][8], bool print)
{//Used as a generic function to calculate if a piece can move into a position, but returns a true value, if the position contains an existing piece
    if(isWithinBoardLimit(row, col))
    {
        if(isEmpty(boardPieces_, row, col))
        {
            PieceLoc tempLoc;
            tempLoc.setRow(row);
            tempLoc.setCol(col);
            tempLoc.setIsEmpty(true);
            possiblePieceLoc_.emplace_back(tempLoc);
            if(print == true)
            {
                tempLoc.printInfo();
            }
            return false;
        }
        else
        { //Colour check only if the location isn't empty
            if(isBoardCharWhite(boardPieces_, row, col) != getColour())
            {
                PieceLoc tempLoc;
                tempLoc.setRow(row);
                tempLoc.setCol(col);
                tempLoc.setIsEmpty(false);
                possiblePieceLoc_.emplace_back(tempLoc);
                if(print == true)
                {
                    tempLoc.printInfo();
                }
            }
            else
            {
                if(print == true)
                {
                    std::cout << position << " pos in " << piece << " is of same colour" << std::endl;
                }
            }
            return true;
        }
        
    }
    else
    {
        if(print == true)
        {
            std::cout << position << " pos in " << piece << " is out of bound" << std::endl;
        }
        return true;
    }
}