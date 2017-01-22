#include "knight.h"

/* KNIGHT */
Knight::Knight(bool p) : Piece(p) {name = "Knight";}

// Knight's moves
list<string> Knight::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	// current pos
	string pos = from;

	// Knight moves; all 8 L shapes
	int f = 1;
	int r = 2;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	// Check within boundary
	if(from[0] + f <= 'H' && from[1] + r <= '8') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	f = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f >= 'A' && from[1] + r <= '8') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	r = 1; f = 2;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f <= 'H' && from[1] + r <= '8') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	f = -2;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f >= 'A' && from[1] + r <= '8') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	r = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f >= 'A' && from[1] + r >= '1') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	f = 2;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f <= 'H' && from[1] + r >= '1') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	r = -2; f = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f >= 'A' && from[1] + r >= '1') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	f = 1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;
	if(from[0] + f <= 'H' && from[1] + r >= '1') {
		if (board[pos] == NULL || board[pos]->player != player)
			moves.push_back(pos);
	}

	return moves;
}
/* END KNIGHT */