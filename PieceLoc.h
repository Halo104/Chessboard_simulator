#ifndef PIECELOC_H_
#define PIECELOC_H_

#include <string>

struct PieceLoc
{
public:
    PieceLoc();
    PieceLoc(const std::string& stringLoc);

    int getRow() const;
    int getCol() const;
    std::string getLoc_() const;
    bool getIsEmpty() const;

    void setRow(int row);
    void setCol(int col);
    void setIsEmpty(bool isEmpty);
    //Helps write whether the piece location isEmpty or not
    void setEmptyValue(const char boardPieces_ [8][8]);
    
    void printInfo();

private:
    int row_;
    int col_;
    std::string loc_;
    bool isEmpty_;
};

#endif //PIECELOC_H_
