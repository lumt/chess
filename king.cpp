#include "king.h"

/* KING */
King::King(bool p) : Piece(p) {name = "King";}

// Function to return a list of available moves by the King
list<string> King::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	// current pos
	string pos = from;

	// Kings can move between 1 square of itself
	for(int f = -1; f <= 1; f++) {

		// If adjacent file is OOB, skip current loop
		if(from[0]+f < 'A' || from[0]+f > 'H')
			continue;

		for(int r = -1; r <= 1; r++) {

			// If adjacent row is OOB, skip
			if(from[1] + r < '1' || from[1] + r > '8')
				continue;
			
			// update position
			pos[0] = from[0] + f;
			pos[1] = from[1] + r;

			// You can move there if empty or piece occupying is not yours
			if(board[pos] == NULL || board[pos]->player != player) {
				moves.push_back(pos);
			}
		}
	}

	return moves;
}
/* END KING */