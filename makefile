chess: ChessMain.o ChessBoard.o ChessPieces.o PieceLoc.o utils.o Pawn.o Bishop.o Rook.o Knight.o King.o Queen.o
	g++ -g ChessMain.o ChessBoard.o ChessPieces.o PieceLoc.o utils.o Pawn.o Bishop.o Rook.o Knight.o King.o Queen.o -o chess
ChessMain.o: ChessMain.cpp ChessBoard.h utils.h  
	g++ -Wall -g -c ChessMain.cpp
ChessBoard.o: ChessBoard.cpp ChessBoard.h PieceLoc.h utils.h ChessPieces.h Pawn.h Bishop.h Rook.h Knight.h King.h Queen.h
	g++ -Wall -g -c ChessBoard.cpp
ChessPieces.o: ChessPieces.cpp  ChessPieces.h PieceLoc.h utils.h  
	g++ -Wall -g -c ChessPieces.cpp
PieceLoc.o: PieceLoc.cpp ChessBoard.h PieceLoc.h utils.h
	g++ -Wall -g -c PieceLoc.cpp
utils.o: utils.cpp utils.h
	g++ -Wall -g -c utils.cpp
Pawn.o: Pawn.cpp Pawn.h
	g++ -Wall -g -c Pawn.cpp
Bishop.o: Bishop.cpp Bishop.h
	g++ -Wall -g -c Bishop.cpp
Rook.o: Rook.cpp Rook.h
	g++ -Wall -g -c Rook.cpp
Knight.o: Knight.cpp Knight.h
	g++ -Wall -g -c Knight.cpp
King.o: King.cpp King.h
	g++ -Wall -g -c King.cpp
Queen.o: Queen.cpp Queen.h
	g++ -Wall -g -c Queen.cpp

clean:
	rm -f *.o chess
