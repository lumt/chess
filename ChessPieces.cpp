#include <iostream>
#include "ChessBoard.h"
#include "ChessPieces.h"


/* PIECE ABSTRACT CLASS */
Piece::Piece(bool p) { player = p; }

// Function to output to outstream
ostream& operator<<(ostream& o, const Piece& p) {
    	return o << (p.player == WHITE? "White's " : "Black's ") << p.name;
}

// Function to see if you can move the piece there or not
bool Piece::movePiece(map<string, Piece*> &board, string from, string to) 
{
	list<string> moves = availableMoves(board, from);

	for(list<string>::iterator iter = moves.begin();
		iter != moves.end(); iter++)
	{
		if(*iter == to)
			return true;
	}

	return false;
}
/* END PIECE */