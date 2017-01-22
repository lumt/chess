#include "queen.h"

/* QUEEN */
Queen::Queen(bool p) : Piece(p) { 
	name = "Queen"; 

	// Queen is composition of rook and bishop
	rook = new Rook(p);
	bishop = new Bishop(p);
}

// Queen's moves
list<string> Queen::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	moves = rook->availableMoves(board, from);

	list<string> bishops = bishop->availableMoves(board, from);

	moves.insert(moves.end(), bishops.begin(), bishops.end());

	return moves;
}
/* END QUEEN */