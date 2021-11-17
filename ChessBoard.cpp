#include "ChessBoard.h"
#include "PieceLoc.h"
#include "utils.h"

#include "ChessPieces.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"

#include <algorithm>
#include <iostream>

ChessBoard::ChessBoard()
{//Constructor used to fill the ChessPiece_ vector and 3 other variables
  turnNum_ = 1;
  blackInCheck_ = false;
  whiteInCheck_ = false;

  whiteKingMoved_ = false;
  whiteLeftRookMoved_ = false;
  whiteRightRookMoved_ = false;
  blackKingMoved_ = false;
  blackLeftRookMoved_ = false;
  blackRightRookMoved_ = false;

  fillChessPieceVector();
  
  std::cout << "A new chess game is started!" << std::endl;
}

ChessBoard::~ChessBoard()
{
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {//Only memory that is heap allocated is the different chess pieces on the ChessBoard
    delete ChessPiece_[i];
  }
  ChessPiece_.clear();
}

void ChessBoard::resetBoard()
{//Deleting all the variables in the vector and resetting all internal variables like the constructor
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {
    delete ChessPiece_[i];
  }
  ChessPiece_.clear();

  turnNum_ = 1;
  blackInCheck_ = false;
  whiteInCheck_ = false;
  
  whiteKingMoved_ = false;
  whiteLeftRookMoved_ = false;
  whiteRightRookMoved_ = false;
  blackKingMoved_ = false;
  blackLeftRookMoved_ = false;
  blackRightRookMoved_ = false;

  fillChessPieceVector();
}

void ChessBoard::fillChessPieceVector()
{//Function used to create all the ChessPieces in the ChessPieces_ vector
  for(int i = 0; i < 8; ++i){
    //Generating pawns
    boardPieces_[6][i] = 'p';
    ChessPiece* pPiece = new Pawn(6, i, 'p', WHITE, 0);
    ChessPiece_.emplace_back(pPiece);

    boardPieces_[1][i] = 'P';
    ChessPiece* PPiece = new Pawn(1, i, 'P', BLACK, 0);
    ChessPiece_.emplace_back(PPiece);

    //Generating empty space
    boardPieces_[2][i] = '-';
    boardPieces_[3][i] = '-';
    boardPieces_[4][i] = '-';
    boardPieces_[5][i] = '-';
  }
  //Generating rooks
  boardPieces_[0][0] = 'R';
  ChessPiece* RPiece1 = new Rook(0, 0, 'R', BLACK, 0);
  ChessPiece_.emplace_back(RPiece1);
  boardPieces_[0][7] = 'R';
  ChessPiece* RPiece2 = new Rook(0, 7, 'R', BLACK, 0);
  ChessPiece_.emplace_back(RPiece2);
  boardPieces_[7][0] = 'r';
  ChessPiece* rPiece1 = new Rook(7, 0, 'r', WHITE, 0);
  ChessPiece_.emplace_back(rPiece1);
  boardPieces_[7][7] = 'r';
  ChessPiece* rPiece2 = new Rook(7, 7, 'r', WHITE, 0);
  ChessPiece_.emplace_back(rPiece2);

  //Generating knights
  boardPieces_[0][1] = 'N';
  ChessPiece* NPiece1 = new Knight(0, 1, 'N', BLACK, 0);
  ChessPiece_.emplace_back(NPiece1);
  boardPieces_[0][6] = 'N';
  ChessPiece* NPiece2 = new Knight(0, 6, 'N', BLACK, 0);
  ChessPiece_.emplace_back(NPiece2);
  boardPieces_[7][1] = 'n';
  ChessPiece* nPiece1 = new Knight(7, 1, 'n', WHITE, 0);
  ChessPiece_.emplace_back(nPiece1);
  boardPieces_[7][6] = 'n';
  ChessPiece* nPiece2 = new Knight(7, 6, 'n', WHITE, 0);
  ChessPiece_.emplace_back(nPiece2);
  
  //Generating bishops
  boardPieces_[0][2] = 'B';
  ChessPiece* BPiece1 = new Bishop(0, 2, 'B', BLACK, 0);
  ChessPiece_.emplace_back(BPiece1);
  boardPieces_[0][5] = 'B';
  ChessPiece* BPiece2 = new Bishop(0, 5, 'B', BLACK, 0);
  ChessPiece_.emplace_back(BPiece2);
  boardPieces_[7][2] = 'b';
  ChessPiece* bPiece1 = new Bishop(7, 2, 'b', WHITE, 0);
  ChessPiece_.emplace_back(bPiece1);
  boardPieces_[7][5] = 'b';
  ChessPiece* bPiece2 = new Bishop(7, 5, 'b', WHITE, 0);
  ChessPiece_.emplace_back(bPiece2);
  
  //Generating queen
  boardPieces_[0][3] = 'Q';
  ChessPiece* QPiece = new Queen(0, 3, 'Q', BLACK, 0);
  ChessPiece_.emplace_back(QPiece);
  boardPieces_[7][3] = 'q';
  ChessPiece* qPiece = new Queen(7, 3, 'q', WHITE, 0);
  ChessPiece_.emplace_back(qPiece);
  
  //Generating king
  boardPieces_[0][4] = 'K';
  ChessPiece* KPiece = new King(0, 4, 'K', BLACK, 0);
  ChessPiece_.emplace_back(KPiece);
  boardPieces_[7][4] = 'k';
  ChessPiece* kPiece = new King(7, 4, 'k', WHITE, 0);
  ChessPiece_.emplace_back(kPiece);
}

void ChessBoard::displayBoard()
{//Prints out the current state of the board
  std::cout << "    ";
  for(int i = 0; i < 8; i++)
  {
    std::cout << static_cast<char>(65+i) << " ";
  }
  std::cout << std::endl;
  std::cout << "    ";
  for(int i = 0; i < 8; i++)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for(int r = 0; r < 8; ++r){
    std::cout << 8 - r << " ";
    std::cout << r << " ";
    for(int c = 0; c < 8; ++c){
      std::cout << boardPieces_[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

void ChessBoard::displayBoard(const char board [8][8])
{//Overload of displayBoard, for when a temporary board is used
  std::cout << "    ";
  for(int i = 0; i < 8; i++)
  {
    std::cout << static_cast<char>(65+i) << " ";
  }
  std::cout << std::endl;
  std::cout << "    ";
  for(int i = 0; i < 8; i++)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for(int r = 0; r < 8; ++r){
    std::cout << 8 - r << " ";
    std::cout << r << " ";
    for(int c = 0; c < 8; ++c){
      std::cout << board[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

void ChessBoard::printSubmitMove(std::string originLoc, std::string endLoc)
{//General function used to confirm the submitmove has translated correctly to internal board array coordinates
  int originArrayRow = 8 - (static_cast<int>(originLoc[1]) - 48);
  int originArrayCol = static_cast<int>(originLoc[0]) - 65;
  int endArrayRow = 8 - (static_cast<int>(endLoc[1]) - 48);
  int endArrayCol = static_cast<int>(endLoc[0]) - 65;
  std::cout << "Submit Move: " << originLoc << ", " << endLoc << "; " << "Origin row: " << originArrayRow 
    << ", col: " << originArrayCol << ", End row: " << endArrayRow << ", col: " << endArrayCol << std::endl;
}

void ChessBoard::printChessPieceVector()
{//Prints out the information for each piece in the ChessPiece_ vector
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {
    std::cout << "address: " << &ChessPiece_[i] << " inPlay: " << ChessPiece_[i]->getInPlay() << " ";
    std::cout << ChessPiece_[i]->getCharPiece() << " row: " << ChessPiece_[i]->getCurrentLoc().getRow() << " col: " << ChessPiece_[i]->getCurrentLoc().getCol() << "; ";
  }
  std::cout << std::endl;
}

std::string ChessBoard::pieceNameIdentifier(char pieceChar)
{//Translates the character on the ChessBoard to it's actual piece name for printing
  std::string pieceName = "Empty";
  if(pieceChar == 'p' || pieceChar == 'P')
  {
    pieceName = "Pawn";
  }
  else if (pieceChar == 'b' || pieceChar == 'B')
  {
    pieceName = "Bishop";
  }
  else if (pieceChar == 'r' || pieceChar == 'R')
  {
    pieceName = "Rook";
  }
  else if (pieceChar == 'n' || pieceChar == 'N')
  {
    pieceName = "Knight";
  }
  else if (pieceChar == 'k' || pieceChar == 'K')
  {
    pieceName = "King";
  }
  else if (pieceChar == 'q' || pieceChar == 'Q')
  {
    pieceName = "Queen";
  }
  return pieceName;
}

void ChessBoard::printMove(const PieceLoc& originLoc, const PieceLoc& endLoc)
{//Function used to print what is happening for the current move
  std::string originPieceName = pieceNameIdentifier(boardPieces_[originLoc.getRow()][originLoc.getCol()]);

  if(whosTurn() == WHITE)
  {
    std::cout << "White's " << originPieceName << " moves from " << originLoc.getLoc_() 
        << " to " << endLoc.getLoc_();

    if(containsPiece(endLoc.getRow(), endLoc.getCol()))
    {
      std::string endPieceName = pieceNameIdentifier(boardPieces_[endLoc.getRow()][endLoc.getCol()]);
      std::cout << " taking Black's " << endPieceName;
    }
    std::cout << std::endl;
  }
  else
  {
    std::cout << "Black's " << originPieceName << " moves from " << originLoc.getLoc_() 
      << " to " << endLoc.getLoc_();
    
    if(containsPiece(endLoc.getRow(), endLoc.getCol()))
    {
      std::string endPieceName = pieceNameIdentifier(boardPieces_[endLoc.getRow()][endLoc.getCol()]);
      std::cout << " taking White's " << endPieceName;
    }
    std::cout << std::endl;
  }
}

bool ChessBoard::containsPiece(int row, int col)
{//Checks that for a given row and column on the live chess board, it is not empty
  if(boardPieces_[row][col] == '-')
  {
    return false;
  }
  return true;
}

int ChessBoard::whosTurn()
{
  return (turnNum_ % 2);
}

void ChessBoard::updateBoard(int row, int col, char piece)
{//Updates the state of the board in the given row and col with the provided character, while also checking input is valid
  if(piece == '-' || piece == 'p' || piece == 'P'|| piece == 'r' || piece == 'R' || piece == 'n' || piece == 'N'
    || piece == 'b' || piece == 'B' || piece == 'q' || piece == 'Q' || piece == 'k' || piece == 'K')
  {
    if(row >= 0 && row <= 7 && col >= 0 && col <= 7)
    {
      boardPieces_[row][col] = piece;
    }
    else { std::cerr << "UpdateBoard Error: not between 0 to 7" << std::endl; }
  }
  else { std::cerr << "UpdateBoard Error: not valid char" << std::endl; }
}

void ChessBoard::updatePieceLoc(PieceLoc& originLoc, PieceLoc& endLoc, char charPiece)
{//Updates the location of chess pieces in the ChessPiece_ vector
  int originIndex = indexOfChessPieceInLoc(originLoc, charPiece);
  //If there is a piece in the end location, placing it out of play - Find piece, ensure opposite colour, put outofplay
  if(containsPiece(endLoc.getRow(), endLoc.getCol()))
  {
    int endIndex = indexOfChessPieceInLoc(endLoc, boardPieces_[endLoc.getRow()][endLoc.getCol()]);
    if(ChessPiece_[originIndex]->getColour() != ChessPiece_[endIndex]->getColour())
    {
      ChessPiece_[endIndex]->setInPlay(false);
    }
    else
    {
      std::string errorMessage = "updatePieceLoc...Origin and end piece colour is the same";
      throw errorMessage;
    }
  }
  //Only update after putting end piece OutOfPlay, or else, origin piece already in end piece loc
  ChessPiece_[originIndex]->getCurrentLoc().setRow(endLoc.getRow());
  ChessPiece_[originIndex]->getCurrentLoc().setCol(endLoc.getCol());
}

int ChessBoard::indexOfChessPieceInLoc (const PieceLoc &originPieceLoc, char charPiece)
{//Searches the ChessPiece_ vector for the index of a chess piece for a given location
  std::string errorMessage;
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  { //Looking for the vector location of the PieceLoc of all pieces
    if(ChessPiece_[i]->getCurrentLoc().getRow() == originPieceLoc.getRow() && ChessPiece_[i]->getCurrentLoc().getCol() == originPieceLoc.getCol())
    {
      if(ChessPiece_[i]->getInPlay() == true)
      {
        if(charPiece == ChessPiece_[i]->getCharPiece())
        {
          return i;
        }
        else
        {
          errorMessage = "indexOfChessPieceInLoc... Found the piece in vector, but it is not a: ";
          errorMessage += charPiece;
          errorMessage += ", instead it is a: ";
          errorMessage += ChessPiece_[i]->getCharPiece();
          throw errorMessage;
        }
      }
    }
    else
    {
      errorMessage = "indexOfChessPieceInLoc... Somehow, no ";
      errorMessage += charPiece;
      errorMessage += " piece in current location, not good!";
    }
  }
  throw errorMessage; //Only throwing the message after going through the whole loop
}

void ChessBoard::submitMove(std::string originLoc, std::string endLoc)
{//Conducts all the checks, printing and move making on the chess board
  try
  {
    //Syntax checks, is the 2 input board locations actually possible locations?
    inputStringCheck(originLoc);
    inputStringCheck(endLoc);

    PieceLoc pieceLocOrigin (originLoc);
    PieceLoc pieceLocEnd (endLoc);
    pieceLocOrigin.setEmptyValue(boardPieces_);
    pieceLocEnd.setEmptyValue(boardPieces_);

    //Logical check, is the 2 input board locations valid chess moves?  
    validPieceSelection(pieceLocOrigin, pieceLocEnd); //Checks: There is a piece in the loc + Correct colour selected

    //Castling logic (has to override, validMoveForPiece logic, as it is an exception case)
    //(i.e. not part of the expected locations the king should be able to move)
    //Recognize initiation of castling
    if(isCastlingRequested(pieceLocOrigin, pieceLocEnd))
    {
      if(isCastlingAllowed(pieceLocOrigin, pieceLocEnd))
      {
        //Print Move that takes place
        printMove(pieceLocOrigin, pieceLocEnd);
        executeCastling(pieceLocOrigin, pieceLocEnd);
      }
      else
      {
        std::string errorMessage = cannotMoveErrorMesGen(pieceLocOrigin, pieceLocEnd);
        throw errorMessage;
      }
    }
    else
    {
      validMoveForPiece(pieceLocOrigin, pieceLocEnd); //Checks: Given origin loc, end loc is possible

      //Does your move cause you to be in-check? (you are currently not in check)
      if((whosTurn() == BLACK && blackInCheck_ == false) || (whosTurn() == WHITE && whiteInCheck_ == false))
      {
        if(doesMoveCauseOwnCheck(pieceLocOrigin, pieceLocEnd))
        {
          std::string errorMessage = "Invalid move, you cause yourself to be in-check";
          throw errorMessage;
        }
      }//You are currently in check, but not check-mate, does your move move you out of check?
      else
      {
        if(doesMoveCauseOwnCheck(pieceLocOrigin, pieceLocEnd))
        {
          std::string errorMessage = "Invalid move, you cause yourself to still be in-check";
          throw errorMessage;
        }
        else
        {
          if(whosTurn() == WHITE){ whiteInCheck_ = false; }
          else { blackInCheck_ = false; }
        }
      }
      //Print Move that takes place
      printMove(pieceLocOrigin, pieceLocEnd);

      //Update board with new location + update vector pieces
      updatePieceLoc(pieceLocOrigin, pieceLocEnd, boardPieces_[pieceLocOrigin.getRow()][pieceLocOrigin.getCol()]);
      if(containsPiece(pieceLocEnd.getRow(), pieceLocEnd.getCol()))
      { //Moving to taken location
        updateBoard(pieceLocEnd.getRow(), pieceLocEnd.getCol(), boardPieces_[pieceLocOrigin.getRow()][pieceLocOrigin.getCol()]);
        updateBoard(pieceLocOrigin.getRow(), pieceLocOrigin.getCol(), '-');    
      }
      else
      { //Moving to empty location
        //Has to be placed before board update, as it relies on board to know what the charPiece is in the origin loc
        updateBoard(pieceLocEnd.getRow(), pieceLocEnd.getCol(), boardPieces_[pieceLocOrigin.getRow()][pieceLocOrigin.getCol()]);
        updateBoard(pieceLocOrigin.getRow(), pieceLocOrigin.getCol(), '-');
      }
    }

    if(whiteKingMoved_ != true || blackKingMoved_ != true)
    {//Only need to check if either king hasn't moved
      checkCastlingConditions();
    }

    //Does your move check your opponent? (done after board is updated)
    if(doesMoveCheckOpp(pieceLocOrigin, pieceLocEnd))
    {
      if(whosTurn() == WHITE)
      {
        blackInCheck_ = true;
      }
      else
      {
        whiteInCheck_ = true;
      }
    }

    turnNum_++; //Incrementing the turn count
    
    //After your move
    //Is your opponent in check-mate? (you opponent is currently in check, and with all the possible moves 
    //,they are unable to move out of check)
    if(whosTurn() == BLACK && blackInCheck_ == true)
    {
      if(isOppCheckmate())
      {
        std::cout << "Black is in checkmate" << std::endl;
      }
      else
      {
        std::cout << "Black is in check" << std::endl;
      }
      
    }
    else if (whosTurn() == WHITE && whiteInCheck_ == true)
    {
      if(isOppCheckmate())
      {
        std::cout << "White is in checkmate" << std::endl;
      }
      else
      {
        std::cout << "White is in check" << std::endl;
      }
    }
    //Does it cause your opponent into stalemate?
    //Meaning, opponent is not in check, but there are no legal moves for them
    else if(whosTurn() == BLACK && blackInCheck_ == false)
    {
      if(isOppCheckmate())
      {
        std::cout << "It is a stalemate" << std::endl;
      }
    }
    else if(whosTurn() == WHITE && whiteInCheck_ == false)
    {
      if(isOppCheckmate())
      {
        std::cout << "It is a stalemate" << std::endl;
      }
    }
  }

  catch (std::string errorMessage)
  {
    //std::cerr << "For originLoc: " << originLoc << ", endLoc: " << endLoc << std::endl;
    std::cerr << errorMessage << std::endl;
  }
  catch(...)
  {
    std::cerr << "Reached default catch block" << std::endl;
  }
}

void ChessBoard::inputStringCheck(std::string Loc)
{//Checks that the input string is valid
  if(!isLength(Loc, 2))
  {
    int tempLength = Loc.length();
    std::string errorMessage = "Input board moves require 2 character input, you inputted: " + Loc + ", which is length: " + std::to_string(tempLength);
    throw errorMessage;
  }

  char firstChar = Loc [0];
  char secondChar = Loc [1];
  if(!isBetweenAtoH(firstChar))
  {
    std::string errorMessage = "First char is not between A and H, you inputted: ";
    errorMessage += firstChar;
    throw errorMessage;
  }
  if(!isNumberBetween1To8(secondChar))
  {
    std::string errorMessage = "Second char is not between 1 and 8, you inputted: ";
    errorMessage += secondChar;
    throw errorMessage;
  }
}

void ChessBoard::validPieceSelection(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc)
{//Checks that the selected start location contains a chess piece, and the chess piece colour is valid
  if(!containsPiece(originPieceLoc.getRow(), originPieceLoc.getCol()))
  {
    std::string errorMessage = "There is no piece at position ";
    errorMessage += originPieceLoc.getLoc_();
    throw errorMessage;
  }
  validColourPiece(originPieceLoc.getRow(), originPieceLoc.getCol(), true);

  if(containsPiece(endPieceLoc.getRow(), endPieceLoc.getCol()))
  {
    validColourPiece(endPieceLoc.getRow(), endPieceLoc.getCol(), false);
  }
}

void ChessBoard::validColourPiece(int row, int col, bool isOriginLoc)
{//Given whos turn it is, check if the piece selected is correct (depending on if it is the start or end location)
  int colourTurn = whosTurn();
  if(isOriginLoc == true){ //Checking for original location
    if(colourTurn == WHITE) //White, than only small letters are valid
    {
      if(!(static_cast<int>(boardPieces_[row][col]) >= static_cast<int>('a') 
        && static_cast<int>(boardPieces_[row][col]) <= static_cast<int>('z')))
      {
        std::string errorMessage = "It is not Black's turn to move";
        //std::string errorMessage = "White moving a black piece, not a valid move";
        throw errorMessage;
      }
    }
    else if(colourTurn == BLACK) //Black, than only caped letters are valid
    {
      if(!(static_cast<int>(boardPieces_[row][col]) >= static_cast<int>('A') 
        && static_cast<int>(boardPieces_[row][col]) <= static_cast<int>('Z')))
      {
        std::string errorMessage = "It is not White's turn to move";
        //std::string errorMessage = "Black moving a white piece, not a valid move";
        throw errorMessage;
      }
    }
  }
  else //Checking for end location
  {
    if(colourTurn == WHITE) //White, than only capped letters are valid
    {
      if(!(static_cast<int>(boardPieces_[row][col]) >= static_cast<int>('A') 
        && static_cast<int>(boardPieces_[row][col]) <= static_cast<int>('Z')))
      {
        std::string errorMessage = "White piece moving towards a white piece, not a valid move";
        throw errorMessage;
      }
    }
    else if(colourTurn == BLACK) //Black, than only small letters are valid
    {
      if(!(static_cast<int>(boardPieces_[row][col]) >= static_cast<int>('a') 
        && static_cast<int>(boardPieces_[row][col]) <= static_cast<int>('z')))
      {
        std::string errorMessage = "Black piece moving towards a black piece, not a valid move";
        throw errorMessage;
      }
    }
  }
}

bool ChessBoard::validMoveForPiece(PieceLoc &originPieceLoc, PieceLoc &endPieceLoc)
{
  //Looks for what piece the origin location contains
  //and checks if the end location matches a calculated possible piece location
  switch(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()])
  {
    case 'p':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'p');
      break;
    }
    case 'P':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'P');
      break;
    }
    case 'b':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'b');
      break;
    }
    case 'B':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'B');
      break;
    }
    case 'r':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'r');
      break;
    }
    case 'R':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'R');
      break;
    }
    case 'n':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'n');
      break;
    }
    case 'N':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'N');
      break;
    }
    case 'k':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'k');
      break;
    }
    case 'K':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'K');
      break;
    }
    case 'q':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'q');
      break;
    }
    case 'Q':
    {
      return isMovePossibleforPiece(originPieceLoc, endPieceLoc, 'Q');
      break;
    }
    default:
    {
      std::string errorMessage = "Reached end of cases in validMoveForPiece";
      throw errorMessage;
    }
  }
  return false;
}

bool ChessBoard::isMovePossibleforPiece(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc, char charPiece)
{//Uses the calPossiblePieceLoc function for the piece to be moved and compares the end location to the possible locations found
  std::string errorMessage;
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  { //Looking for the vector location of the PieceLoc of all pieces
    if(ChessPiece_[i]->getCurrentLoc().getRow() == originPieceLoc.getRow() 
      && ChessPiece_[i]->getCurrentLoc().getCol() == originPieceLoc.getCol() && ChessPiece_[i]->getInPlay() == true)
    {
      if(charPiece == ChessPiece_[i]->getCharPiece())
      {
        ChessPiece_[i]->calPossiblePieceLoc(boardPieces_, false); //Requesting to calculate all possible locations for this piece
        for(int j = 0; j < ChessPiece_[i]->getSizePossibleLoc(); j++)
        { //Once calculated, see if detination location matches any of the possible locations
          if(ChessPiece_[i]->getPossibleLoc(j).getRow() == endPieceLoc.getRow() && ChessPiece_[i]->getPossibleLoc(j).getCol() == endPieceLoc.getCol())
          {
            return true;
          }
          else
          {
            errorMessage = cannotMoveErrorMesGen(originPieceLoc, endPieceLoc);
          }
        }
        if(ChessPiece_[i]->getSizePossibleLoc() == 0)
        {
          errorMessage = cannotMoveErrorMesGen(originPieceLoc, endPieceLoc);
        }
        break;
      }
      else
      {
        errorMessage = "isMovePossibleforPiece... Found the piece in vector, but it is not a: ";
        errorMessage += charPiece;
        throw errorMessage;
      }
    }
    else
    {
      errorMessage = "isMovePossibleforPiece... Somehow, no ";
      errorMessage += charPiece;
      errorMessage += " piece in current location, not good!";
    }
  }
  throw errorMessage; //Only throwing the message after going through the whole loop
  return false;    
}

//!!Does your move cause you to be in-check (if you are in check) ? or does your move, move you out of check?
bool ChessBoard::doesMoveCauseOwnCheck(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc) 
{
  if(whosTurn() == WHITE)//If it is white's turn
  {
    return doesMoveCauseOwnCheckHelper(originPieceLoc, endPieceLoc, WHITE);
  }
  else //Blacks turn
  {
    return doesMoveCauseOwnCheckHelper(originPieceLoc, endPieceLoc, BLACK);
  }
  return false;
}

bool ChessBoard::doesMoveCauseOwnCheckHelper(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc, bool colour)
{
  char charKingPiece;
  std::string colourString;
  if(colour == WHITE)
  {
    charKingPiece = 'k';
    colourString = "White";
  }
  else
  {
    charKingPiece = 'K';
    colourString = "Black";
  }
  //Creating a temporary board
  char tempBoardPieces [8][8];
  for(int r = 0; r < 8; ++r)
  {
    for(int c = 0; c < 8; ++c)
    {
      tempBoardPieces[r][c] = boardPieces_[r][c];
    }
  }
  //Editing the temp board, to reflect the move made
  char originCharPiece = boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()];
  tempBoardPieces[endPieceLoc.getRow()][endPieceLoc.getCol()] = originCharPiece;
  tempBoardPieces[originPieceLoc.getRow()][originPieceLoc.getCol()] = '-';
  
  PieceLoc kingLoc = locOfCharPiece(charKingPiece, tempBoardPieces); //What is the position of your king? in the new temp board

  //If there was a piece at the end location, need to temporarily put it OutOfPlay
  int indexOfEndLoc = -1;
  if(containsPiece(endPieceLoc.getRow(), endPieceLoc.getCol()))
  {
    for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
    {
      if(ChessPiece_[i]->getInPlay() == true && ChessPiece_[i]->getCurrentLoc().getRow() == endPieceLoc.getRow() 
        && ChessPiece_[i]->getCurrentLoc().getCol() == endPieceLoc.getCol())
      {
        indexOfEndLoc = i;
        break;
      }
    }
    ChessPiece_[indexOfEndLoc]->setInPlay(false);
  }

  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {//Using this temporary board, calculate if any of your opponents pieces can attack your king
    if(ChessPiece_[i]->getColour() == !colour && ChessPiece_[i]->getInPlay() == true)
    {
      ChessPiece_[i]->calPossiblePieceLoc(tempBoardPieces, false);
      for(int j = 0; j < ChessPiece_[i]->getSizePossibleLoc(); j++)
      {
        if(ChessPiece_[i]->getPossibleLoc(j).getRow() == kingLoc.getRow() && 
          ChessPiece_[i]->getPossibleLoc(j).getCol() == kingLoc.getCol())
        {
          if(containsPiece(endPieceLoc.getRow(), endPieceLoc.getCol()))
          {//Reverting the piece at the end location that was put OutOfPlay
            ChessPiece_[indexOfEndLoc]->setInPlay(true);
          }
          return true;
        }
      }
    }
  }
  if(containsPiece(endPieceLoc.getRow(), endPieceLoc.getCol()))
  {//Reverting the piece at the end location that was put OutOfPlay
    ChessPiece_[indexOfEndLoc]->setInPlay(true);
  }
  return false;
}

PieceLoc ChessBoard::locOfCharPiece(char charPiece)
{//Used to find the location of the King on the live board
  PieceLoc tempPieceLoc;
  for(int r = 0; r < 8; ++r)
  {
    for(int c = 0; c < 8; ++c)
    {
        if(boardPieces_[r][c] == charPiece)
        {
          tempPieceLoc.setRow(r);
          tempPieceLoc.setCol(c);
          return tempPieceLoc;
          break;
        }
    }
  }
  std::cerr << "locOfCharPiece..Piece not found, returned empty variable" << std::endl;
  return tempPieceLoc;
}

PieceLoc ChessBoard::locOfCharPiece(char charPiece, const char tempBoard [8][8])
{//Used to find the location of the King a temporary board
  PieceLoc tempPieceLoc;
  for(int r = 0; r < 8; ++r)
  {
    for(int c = 0; c < 8; ++c)
    {
        if(tempBoard[r][c] == charPiece)
        {
          tempPieceLoc.setRow(r);
          tempPieceLoc.setCol(c);
          return tempPieceLoc;
          break;
        }
    }
  }
  std::cerr << "locOfCharPiece..Piece not found, returned empty variable" << std::endl;
  return tempPieceLoc;
}

//Does your current move mean your opponent is in check? (done after board is updated)
bool ChessBoard::doesMoveCheckOpp(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc)
{
  if(whosTurn() == WHITE)//Which colour is this turn?
  {
    return doesMoveCheckOppHelper(WHITE);
  }
  else //Blacks turn
  {
    return doesMoveCheckOppHelper(BLACK);
  }
  return false;
}

bool ChessBoard::doesMoveCheckOppHelper(bool colour)
{//Helper function to calculate if your move check your opponent, for the live board
  char charOppKingPiece;
  std::string colourString;
  if(colour == WHITE)
  {
    charOppKingPiece = 'K';
    colourString = "White";
  }
  else
  {
    charOppKingPiece = 'k';
    colourString = "Black";
  }
  PieceLoc oppkingLoc = locOfCharPiece(charOppKingPiece); //What is the position of your opponent's king?

  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {//Using the updated board to calculate if any of your pieces can attack your opponent's king
    if(ChessPiece_[i]->getColour() == colour && ChessPiece_[i]->getInPlay() == true)
    {
      ChessPiece_[i]->calPossiblePieceLoc(boardPieces_, false);
      for(int j = 0; j < ChessPiece_[i]->getSizePossibleLoc(); j++)
      {
        if(ChessPiece_[i]->getPossibleLoc(j).getRow() == oppkingLoc.getRow() && 
          ChessPiece_[i]->getPossibleLoc(j).getCol() == oppkingLoc.getCol())
          {
            return true;
          }
      }
    }
  }
  return false;
}

bool ChessBoard::doesMoveCheckOppHelper(const char tempBoard [8][8], bool colour)
{//Overload of doesMoveCheckOppHelper, so it can be used for temp boards too
  char charOppKingPiece;
  std::string colourString;
  if(colour == WHITE)
  {
    charOppKingPiece = 'K';
    colourString = "White";
  }
  else
  {
    charOppKingPiece = 'k';
    colourString = "Black";
  }
  PieceLoc oppkingLoc = locOfCharPiece(charOppKingPiece, tempBoard); //What is the position of your opponent's king?

  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {//Using the updated board to calculate if any of your pieces can attack your opponent's king
    if(ChessPiece_[i]->getColour() == colour && ChessPiece_[i]->getInPlay() == true)
    {
      ChessPiece_[i]->calPossiblePieceLoc(tempBoard, false);
      for(int j = 0; j < ChessPiece_[i]->getSizePossibleLoc(); j++)
      {
        if(ChessPiece_[i]->getPossibleLoc(j).getRow() == oppkingLoc.getRow() && 
          ChessPiece_[i]->getPossibleLoc(j).getCol() == oppkingLoc.getCol())
          {
            return true;
          }
      }
    }
  }
  return false;
}

//After your move, Is your opponent in check-mate? 
//(you are currently in check, and with all the possible moves, you are unable to move out of check)
bool ChessBoard::isOppCheckmate()
{
  if(whosTurn() == WHITE)
  {
    return isOppCheckmateHelper(WHITE);
  }
  else
  {
    return isOppCheckmateHelper(BLACK);
  }
}

bool ChessBoard::isOppCheckmateHelper(bool colour)
{
  for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
  {
    if(ChessPiece_[i]->getColour() == colour && ChessPiece_[i]->getInPlay() == true)
    { //Find each of your piece that is still in play
      ChessPiece_[i]->calPossiblePieceLoc(boardPieces_, false); //Calculate all possible moves with current 'live' board
      if(ChessPiece_[i]->getSizePossibleLoc() != 0) //Only want to calculate when there are possibilities
      {
        for(int j = 0; j < ChessPiece_[i]->getSizePossibleLoc(); j++)
        {//for each possible move location, move the temp board and check if still in-check
          PieceLoc tempOriginLoc;
          PieceLoc tempEndLoc;
          tempOriginLoc.setRow(ChessPiece_[i]->getCurrentLoc().getRow());
          tempOriginLoc.setCol(ChessPiece_[i]->getCurrentLoc().getCol());
          tempEndLoc.setRow(ChessPiece_[i]->getPossibleLoc(j).getRow());
          tempEndLoc.setCol(ChessPiece_[i]->getPossibleLoc(j).getCol());
          //Create temp board
          char tempBoardPieces [8][8];
          for(int r = 0; r < 8; ++r)
          {
            for(int c = 0; c < 8; ++c)
            {
              tempBoardPieces[r][c] = boardPieces_[r][c];
            }
          }
          //Editing the temp board, to reflect the move made
          char oringinCharPiece = boardPieces_[tempOriginLoc.getRow()][tempOriginLoc.getCol()];
          tempBoardPieces[tempEndLoc.getRow()][tempEndLoc.getCol()] = oringinCharPiece;
          tempBoardPieces[tempOriginLoc.getRow()][tempOriginLoc.getCol()] = '-';

          //Need to temporarily to put end piece OutOfPlay
          if(containsPiece(tempEndLoc.getRow(), tempEndLoc.getCol()))
          {
            int indexOfEndLoc = -1;
            for(int i = 0; i < static_cast<int>(ChessPiece_.size()); i++)
            {
              if(ChessPiece_[i]->getInPlay() == true && ChessPiece_[i]->getCurrentLoc().getRow() == tempEndLoc.getRow() && ChessPiece_[i]->getCurrentLoc().getCol() == tempEndLoc.getCol())
              {
                indexOfEndLoc = i;
                break;
              }
            }
            ChessPiece_[indexOfEndLoc]->setInPlay(false);
            if(!doesMoveCheckOppHelper(tempBoardPieces, !colour))
            { //Given the temp board location, find out if you are still in check
              ChessPiece_[indexOfEndLoc]->setInPlay(true);
              return false;
            }
            else
            { //If you are still in check, keep testing next possible move
              ChessPiece_[indexOfEndLoc]->setInPlay(true);
            }
          }
          else
          { //A lot simplier, no need to temp put any piece out of play
            if(!doesMoveCheckOppHelper(tempBoardPieces, !colour))
            {
              return false;
            }
          }
          
        }
      }
    }
  }
  return true;
}

bool ChessBoard::isCastlingRequested(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc)
{
  char kingChar = ' ';
  int twoStepsLeft = originPieceLoc.getCol() - 2;
  int twoStepsRight = originPieceLoc.getCol() + 2;
  if(whosTurn() == WHITE)
  {
    kingChar = 'k';
  }
  else
  {
    kingChar = 'K';
  }
  
  if(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()] == kingChar)
  {//Check that king is the piece selected to move
    if(whosTurn() == WHITE && (endPieceLoc.getRow() != 7) && (originPieceLoc.getCol() != 4))
    {//Shouldn't really be required, as it is already checked in has King moved, but extra check
      return false;
    }
    if(whosTurn() == BLACK && (originPieceLoc.getRow() != 0) && (endPieceLoc.getCol() != 4))
    {//Shouldn't really be required, as it is already checked in has King moved, but extra check
      return false;
    }
    if(originPieceLoc.getRow() == endPieceLoc.getRow() 
      && (endPieceLoc.getCol() == twoStepsLeft || endPieceLoc.getCol() == twoStepsRight)
      && !containsPiece(endPieceLoc.getRow(), endPieceLoc.getCol()))
    { //Only move if king is being moved 2 steps left or right, and end destination is empty
      return true;
    }
  }
  else
  {
    return false;
  }
  return false;
}

void ChessBoard::checkCastlingConditions()
{//During each valid move, checks whether king or rooks have moved
  if(boardPieces_[7][4] != 'k') { whiteKingMoved_ = true; }
  if(boardPieces_[7][0] != 'r') { whiteLeftRookMoved_ = true; }
  if(boardPieces_[7][7] != 'r') { whiteRightRookMoved_ = true; }
  if(boardPieces_[0][4] != 'K') { blackKingMoved_ = true; }
  if(boardPieces_[0][0] != 'R') { blackLeftRookMoved_ = true; }
  if(boardPieces_[0][7] != 'R') { blackRightRookMoved_ = true; }
}

bool ChessBoard::isCastlingAllowed(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc)
{
  bool isCastlingLeft; //If false then is castling right
  if(endPieceLoc.getCol() == (originPieceLoc.getCol() - 2))
  {
    isCastlingLeft = true;
  }
  else
  {
    isCastlingLeft = false;
  }
  
  if(whosTurn() == WHITE && whiteInCheck_ == false)
  {
    if(whiteKingMoved_ == false && whiteLeftRookMoved_ == false && isCastlingLeft)
    {//Check if king and left rook hasnt moved
      if(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-1] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-2] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-3] == '-')
      {//Check that there is nothing between king and rook
        //Create temp board
        char tempBoardPieces [8][8];
        for(int r = 0; r < 8; ++r)
        {
          for(int c = 0; c < 8; ++c)
          {
            tempBoardPieces[r][c] = boardPieces_[r][c];
          }
        }
        //Update temp board with one move to left
        tempBoardPieces[7][3] = 'k';
        tempBoardPieces[7][4] = '-';
        if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
        {
          tempBoardPieces[7][2] = 'k';
          tempBoardPieces[7][3] = '-';
          if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
          {
            return true;
          }
        }
      }
    }
    else if(whiteKingMoved_ == false && whiteRightRookMoved_ == false && (!isCastlingLeft))
    {//Check if king and right rook hasnt moved
      if(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()+1] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()+2] == '-')
      {//Check that there is nothing between king and rook
        //Create temp board
        char tempBoardPieces [8][8];
        for(int r = 0; r < 8; ++r)
        {
          for(int c = 0; c < 8; ++c)
          {
            tempBoardPieces[r][c] = boardPieces_[r][c];
          }
        }
        //Update temp board with one move to right
        tempBoardPieces[7][5] = 'k';
        tempBoardPieces[7][4] = '-';
        if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
        {
          tempBoardPieces[7][6] = 'k';
          tempBoardPieces[7][5] = '-';
          if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
          {
            return true;
          }
        }
      }
    }
  }
  else if (whosTurn() == BLACK && blackInCheck_ == false)
  {
    if(blackKingMoved_ == false && blackLeftRookMoved_ == false && isCastlingLeft)
    {//Check if king and left rook hasnt moved
      if(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-1] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-2] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()-3] == '-')
      {//Check that there is nothing between king and rook
        //Create temp board
        char tempBoardPieces [8][8];
        for(int r = 0; r < 8; ++r)
        {
          for(int c = 0; c < 8; ++c)
          {
            tempBoardPieces[r][c] = boardPieces_[r][c];
          }
        }
        //Update temp board with one move to left
        tempBoardPieces[0][3] = 'K';
        tempBoardPieces[0][4] = '-';
        if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
        {
          tempBoardPieces[0][2] = 'K';
          tempBoardPieces[0][3] = '-';
          if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
          {
            return true;
          }
        }
      }
    }
    else if(blackKingMoved_ == false && blackRightRookMoved_ == false && (!isCastlingLeft))
    {//Check if king and right rook hasnt moved
      if(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()+1] == '-'
        && boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()+2] == '-')
      {//Check that there is nothing between king and rook
        //Create temp board
        char tempBoardPieces [8][8];
        for(int r = 0; r < 8; ++r)
        {
          for(int c = 0; c < 8; ++c)
          {
            tempBoardPieces[r][c] = boardPieces_[r][c];
          }
        }
        //Update temp board with one move to right
        tempBoardPieces[0][5] = 'K';
        tempBoardPieces[0][4] = '-';
        if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
        {
          tempBoardPieces[0][6] = 'K';
          tempBoardPieces[0][5] = '-';
          if(!doesMoveCheckOppHelper(tempBoardPieces, !(whosTurn())))
          {
            return true;
          }
        }
      }
    }
      
  }
  return false; //Cannot castle if none of the conditions are met to return true  
}

void ChessBoard::executeCastling(PieceLoc &originPieceLoc, PieceLoc &endPieceLoc)
{
  if(endPieceLoc.getCol() == (originPieceLoc.getCol() - 2))
  {//Castling left
    //Updating king location
    updatePieceLoc(originPieceLoc, endPieceLoc, boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()]);
    //Updating rook location
    PieceLoc tempRookStartLoc;
    tempRookStartLoc.setRow(originPieceLoc.getRow());
    tempRookStartLoc.setCol(0);
    PieceLoc tempRookEndLoc;
    tempRookEndLoc.setRow(originPieceLoc.getRow());
    tempRookEndLoc.setCol(3);
    updatePieceLoc(tempRookStartLoc, tempRookEndLoc, boardPieces_[originPieceLoc.getRow()][0]);
    //Updating the live board
    updateBoard(originPieceLoc.getRow(), 2, boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()]);
    updateBoard(originPieceLoc.getRow(), originPieceLoc.getCol(), '-');
    updateBoard(originPieceLoc.getRow(), 3, boardPieces_[originPieceLoc.getRow()][0]);
    updateBoard(originPieceLoc.getRow(), 0, '-');
  }
  else
  {//Castling right
    //Updating king location
    updatePieceLoc(originPieceLoc, endPieceLoc, boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()]);
    //Updating rook location
    PieceLoc tempRookStartLoc;
    tempRookStartLoc.setRow(originPieceLoc.getRow());
    tempRookStartLoc.setCol(7);
    PieceLoc tempRookEndLoc;
    tempRookEndLoc.setRow(originPieceLoc.getRow());
    tempRookEndLoc.setCol(5);
    updatePieceLoc(tempRookStartLoc, tempRookEndLoc, boardPieces_[originPieceLoc.getRow()][7]);
    //Updating the live board
    updateBoard(originPieceLoc.getRow(), 6, boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()]);
    updateBoard(originPieceLoc.getRow(), originPieceLoc.getCol(), '-');
    updateBoard(originPieceLoc.getRow(), 5, boardPieces_[originPieceLoc.getRow()][7]);
    updateBoard(originPieceLoc.getRow(), 7, '-');
  }
}

std::string ChessBoard::cannotMoveErrorMesGen(const PieceLoc &originPieceLoc, const PieceLoc &endPieceLoc)
{
  std::string errorMessage;
  std::string originPieceName = pieceNameIdentifier(boardPieces_[originPieceLoc.getRow()][originPieceLoc.getCol()]);
  if(whosTurn() == WHITE)
  {
    errorMessage = "White's ";
    errorMessage += originPieceName;
    errorMessage += " cannot move to ";
    errorMessage += endPieceLoc.getLoc_();
  }
  else
  {
    errorMessage = "Black's ";
    errorMessage += originPieceName;
    errorMessage += " cannot move to ";
    errorMessage += endPieceLoc.getLoc_();
  }
  return errorMessage;
}