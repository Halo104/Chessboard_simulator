#include "ChessBoard.h"
#include "PieceLoc.h"
#include "utils.h"

#include <string>
#include <iostream>

PieceLoc::PieceLoc()
{
    row_ = -1;
    col_ = -1;
    loc_ = "empty";
    isEmpty_ = 1;
}

PieceLoc::PieceLoc(const std::string& stringLoc) : loc_ (stringLoc)
{
    row_ = 8 - (static_cast<int>(stringLoc[1]) - 48);
    col_ = static_cast<int>(stringLoc[0]) - 65;
    isEmpty_ = 1;
}

int PieceLoc::getRow() const
{
    return row_;
}
int PieceLoc::getCol() const
{
    return col_;
}
std::string PieceLoc::getLoc_() const
{
    return loc_;
}
bool PieceLoc::getIsEmpty() const
{
    return isEmpty_;
}

void PieceLoc::setRow(int row)
{
    row_ = row;
}
void PieceLoc::setCol(int col)
{
    col_ = col;
}
void PieceLoc::setIsEmpty(bool isEmpty)
{
    isEmpty_ = isEmpty;
}

void PieceLoc::setEmptyValue(const char boardPieces_ [8][8])
{
    isEmpty_ = (boardPieces_[row_][col_] == '-');
}

void PieceLoc::printInfo()
{
    std::cout << "PieceLoc Info, row_: " << row_ << ", col_: " << col_ << ", Loc_: " << loc_ << ", isEmpty: " << isEmpty_ << std::endl;
}
