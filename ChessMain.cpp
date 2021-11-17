#include "ChessBoard.h"
#include "utils.h"

#include <iostream>

using namespace std;

int main() {
	ChessBoard cb;
	//cb.displayBoard();

	cout << "=======================\n";
  cout << "Targeted castling tests\n";
  cout << "=======================\n";

  cout << '\n';

  cb.submitMove("E2", "E4");
  cb.submitMove("E7", "E5");
  cout << '\n';

  cb.submitMove("G1", "F3");
  cb.submitMove("G8", "F6");
  cout << '\n';

  cb.submitMove("F1", "C4");
  cb.submitMove("E8", "G8"); // should fail because B at F8
  cb.submitMove("F8", "C5");
  cout << '\n';

  cb.submitMove("F3", "H4");
  cb.submitMove("E8", "F8");
  cout << '\n';

  cb.submitMove("F2", "F3");
  cb.submitMove("F8", "E8");
  cout << '\n';

  cb.submitMove("E1", "G1"); // should fail because G1 in check
  cb.submitMove("D2", "D3");
  cb.submitMove("E8", "G8"); // should fail because not King's first move
  cb.submitMove("C5", "B4");

  cb.submitMove("E1", "G1"); // should fail because White in check
  cb.submitMove("C2", "C3");
  cb.submitMove("F6", "E4");
  cout << '\n';

  cb.submitMove("A2", "A3");
  cb.submitMove("E4", "G3");
  cout << '\n';

  cb.submitMove("E1", "G1"); // should fail because F1 in check
  cb.submitMove("H2", "G3");
  cb.submitMove("A7", "A6");
  cout << '\n';

  cb.submitMove("E1", "G1"); // should succeed
  cout << '\n';


	/*
	cb.submitMove("A2", "A4");
	cb.submitMove("D7", "D5");
	cb.submitMove("C2", "C4");
	cb.submitMove("C7", "C6");
	cb.submitMove("B2", "B3");
	cb.submitMove("C8", "F5");
	cb.submitMove("C1", "A3");
	cb.submitMove("C6", "C4");
	cb.submitMove("H7", "H5");
	cb.submitMove("A1", "A2");
	cb.submitMove("H8", "H7");
	cb.submitMove("G1", "G3");
	cb.submitMove("G1", "H3");
	cb.submitMove("E7", "E5");
	cb.submitMove("D2", "D3");
	cb.submitMove("E8", "E7");
	cb.submitMove("E1", "D2");
	cb.submitMove("D8", "A5");
	cb.submitMove("D1", "C1");
	*/

//Example game found online
/*
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E5");
	cb.submitMove("G1", "F3");
	cb.submitMove("G8", "F6");
	cb.submitMove("F1", "C4");
	cb.submitMove("F6", "E4");
	cb.submitMove("B1", "C3");
	cb.submitMove("E4", "C5");
	cb.submitMove("F3", "E5");
	cb.submitMove("F7", "F6");
	cb.submitMove("D1", "H5");
	cb.submitMove("G7", "G6");
	cb.submitMove("C4", "F7");
	cb.submitMove("E8", "E7");
	cb.submitMove("C3", "D5");
	cb.submitMove("E7", "D6");
	cb.submitMove("E5", "C4");
	cb.submitMove("D6", "C6");
	cb.submitMove("D5", "B4");
	cb.submitMove("C6", "B5");
	cb.submitMove("A2", "A4");
	cb.submitMove("B5", "B4");
	cb.submitMove("C2", "C3");
	cb.submitMove("B4", "B3");
	cb.submitMove("H5", "D1");
*/

  /*
  cout << "========================\n";
  cout << "Testing the Chess Engine\n";
  cout << "========================\n\n";
  
	//ChessBoard cb;
	cout << '\n';

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';
	
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';

	cb.submitMove("D3", "G6");
	cout << '\n';
	*/

	/*
	//Testing reset function
	cb.displayBoard();
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';

	cb.resetBoard();
	cb.displayBoard();
	cb.submitMove("E2", "E2");
	*/

	return 0;
}
