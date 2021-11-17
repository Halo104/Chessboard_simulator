#include "utils.h"

#include <iostream>

bool isNumberBetween1To8(char inputChar)
{//Checks character is between 1 and 8 in ASCII values
  int inputCharValue = static_cast<int>(inputChar);
    
  if (inputCharValue > 56 || inputCharValue < 49)
  {
      return false;
  }
  return true;
}

bool isBetweenAtoH(char inputChar)
{//Checks character is between A and H in ASCII values
    int inputCharValue = static_cast<int>(inputChar);
    if (inputCharValue > 72 || inputCharValue < 65)
    {
        return false;
    }
    return true;
}

bool isLength(std::string inputString, int length)
{//Compares the string length and expected length
    int inputLength = inputString.length();
    return inputLength == length;
}

void displayBoard_util(const char board [8][8])
{//Given an array of characters, it outputs the board to be displayed
  for(int r = 0; r < 8; ++r){
    for(int c = 0; c < 8; ++c){
      std::cout << board[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

bool isWithinBoardLimit(int row, int col)
{//Checks the row and column input is within internal limit of 0 to 7
    return (row >= 0 && row <= 7 && col >= 0 && col <= 7);
}

bool isEmpty(const char board [8][8], int row, int col)
{//Checks for a given row and column location on a board, it is empty
  return (board [row][col] == '-');
}

bool isBoardCharWhite(const char board [8][8], int row, int col)
{
  std::string errorMessage;
  //Given the character in the board is Capped, it is black
  if(static_cast<int>(board[row][col]) >= 65 && static_cast<int>(board[row][col]) <= 90)
  {
    return false;
  }
  else if (static_cast<int>(board[row][col]) >= 97 && static_cast<int>(board[row][col]) <= 122)
  {
    return true;
  }
  else
  {
    std::cerr << "Error, isBoardCharWhite check is neither letters, so most prob blank '-', but returned false " << std::endl;
  }
  return false;
}