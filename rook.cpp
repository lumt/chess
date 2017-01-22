#include "rook.h"

/* ROOK */
Rook::Rook(bool p) : Piece(p) {name = "Rook";}

// Rook's moves
list<string> Rook::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	// current pos
	string pos = from;

	// Horizontally and vertically (rook)
	int f = 1;
	int r = 0;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	// -> direction
	while (pos[0] <= 'H' && board[pos] == NULL)
	{
		// add pos
		moves.push_back(pos);

		// update next pos
		f++;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	// Checks if oppos is in sight
	if (pos[0] <= 'H' && board[pos]->player != player)
		moves.push_back(pos);


	// <- direction
	f = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[0] >= 'A' && board[pos] == NULL)
	{
		moves.push_back(pos);
		f--;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[0] >= 'A' && board[pos]->player != player)
		moves.push_back(pos);

	// ^ direction
	f = 0; r = 1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[1] <= '8' && board[pos] == NULL)
	{
		moves.push_back(pos);
		r++;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[1] <= '8' && board[pos]->player != player)
		moves.push_back(pos);

	// v direction
	f = 0; r = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[1] >= '1' && board[pos] == NULL)
	{
		moves.push_back(pos);
		r--;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[1] >= '1' && board[pos]->player != player)
		moves.push_back(pos);

	return moves;
}
/* END ROOK */