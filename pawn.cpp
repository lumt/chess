#include "pawn.h"

/* PAWN */
Pawn::Pawn(bool p) : Piece(p) {name = "Pawn";}

// Pawn's moves
list<string> Pawn::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	// current pos
	string pos = from;

	int f, r;

	// Pawn moves depends on player
	// for while pawns
	if (player == WHITE) {
		f = 0; r = 1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;

		// If square in front is empty:
		if (from[1] + r <= '8' && board[pos] == NULL) {
			moves.push_back(pos);

			// from starting position
			if (from[1] == '2') {
				r = 2;
				pos[0] = from[0] + f;
				pos[1] = from[1] + r;
				if (board[pos] == NULL) {
					moves.push_back(pos);
				}
			}
		}

		// If diagonal squares are not empty
		r = 1; f = 1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
		if (from[1] + r <= '8' && from[0] + f <= 'H' &&
			board[pos] && board[pos]->player != player)
			moves.push_back(pos);

		f = -1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
		if (from[1] + r <= '8' && from[0] + f >= 'A' &&
			board[pos] && board[pos]->player != player)
			moves.push_back(pos);
	}


	// For black pawns
	if (player == BLACK) {
		f = 0; r = -1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;

		// If square in front is empty:
		if (from[1] + r >= '1' && board[pos] == NULL) {
			moves.push_back(pos);

			// from starting position
			if (from[1] == '7') {
				r = -2;
				pos[0] = from[0] + f;
				pos[1] = from[1] + r;

				if (board[pos] == NULL) {
					moves.push_back(pos);
				}
			}
		}

		// If diagonal squares are not empty
		r = -1; f = 1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;

		if (from[1] + r >= '1' && from[0] + f <= 'H' &&
			board[pos] && board[pos]->player != player)
			moves.push_back(pos);

		f = -1;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;

		if (from[1] + r >= '1' && from[0] + f >= 'A' &&
			board[pos] && board[pos]->player != player)
			moves.push_back(pos);
	}

	return moves;
}