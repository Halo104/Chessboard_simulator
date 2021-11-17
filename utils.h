#define BLACK 0
#define WHITE 1

#ifndef UTILS_H_
#define UTILS_H_

#include <string>

bool isNumberBetween1To8(char inputChar);
bool isBetweenAtoH(char inputChar);
bool isLength(std::string inputString, int length);
void displayBoard_util(const char board [8][8]);
bool isWithinBoardLimit(int row, int col);
bool isEmpty(const char board [8][8], int row, int col);
bool isBoardCharWhite(const char board [8][8], int row, int col);

#endif //UTILS_H_
