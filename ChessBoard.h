#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "PieceLoc.h"
#include "ChessPieces.h"
#include "utils.h"

#include <string>
#include <vector>

class ChessBoard 
{
private:
  int turnNum_;
  std::vector<ChessPiece*> ChessPiece_;
  bool blackInCheck_;
  bool whiteInCheck_;
  bool whiteKingMoved_;
  bool whiteLeftRookMoved_;
  bool whiteRightRookMoved_;
  bool blackKingMoved_;
  bool blackLeftRookMoved_;
  bool blackRightRookMoved_;

  void fillChessPieceVector();

  void printSubmitMove(std::string originLoc, std::string endLoc);
  void printChessPieceVector();
  std::string pieceNameIdentifier(char pieceChar);
  void printMove(const PieceLoc& originLoc, const PieceLoc& endLoc);

  bool containsPiece(int row, int col);
  int whosTurn(); //0 for black, 1 for white
  void updateBoard(int row, int col, char piece);
  void updatePieceLoc(PieceLoc& originLoc, PieceLoc& endLoc, char charPiece);
  int indexOfChessPieceInLoc (const PieceLoc &originPieceLoc, char charPiece);

  void inputStringCheck(std::string Loc);

  void validPieceSelection(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);
  void validColourPiece(int row, int col, bool isOriginLoc);

  bool validMoveForPiece(PieceLoc &originPieceLoc, PieceLoc &endPieceLoc);
  bool isMovePossibleforPiece(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc, char charPiece);
  
  bool doesMoveCauseOwnCheck(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);
  bool doesMoveCauseOwnCheckHelper(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc, bool colour);
  PieceLoc locOfCharPiece(char charPiece);
  PieceLoc locOfCharPiece(char charPiece, const char boardPieces_ [8][8]);

  bool doesMoveCheckOpp(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);
  bool doesMoveCheckOppHelper(bool colour);
  bool doesMoveCheckOppHelper(const char boardPieces_ [8][8], bool colour);

  bool isOppCheckmate();
  bool isOppCheckmateHelper(bool colour);
  
  bool isCastlingRequested(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);
  void checkCastlingConditions();
  bool isCastlingAllowed(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);
  void executeCastling(PieceLoc &originPieceLoc, PieceLoc &endPieceLoc);

  std::string cannotMoveErrorMesGen(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc);

public:
  char boardPieces_ [8][8]; //row, column

  ChessBoard();
  ~ChessBoard();
  void resetBoard();

  void displayBoard();
  void displayBoard(const char tempBoardPieces [8][8]);

  void submitMove(std::string originLoc, std::string endLoc);
};

#endif //CHESSBOARD_B_