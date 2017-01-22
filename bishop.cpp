#include "bishop.h"

/* BISHOP */
// Constructor
Bishop::Bishop(bool p) : Piece(p) {name = "Bishop";}

// Function to get all avialable moves for the Bishop
list<string> Bishop::availableMoves(map<string, Piece*> &board, string from)
{
	list<string> moves;

	// current pos
	string pos = from;

	int f = 1;
	int r = 1;

	// update position
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	// '/' UP direction
	// add all blank squares in line within the board
	while (pos[0] <= 'H' && pos[1] <= '8' && board[pos] == NULL) 
	{
		// add pos
		moves.push_back(pos);

		// update next pos
		f++;
		r++;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	// Checks if within board and opponent is in line of sight
	if (pos[0] <= 'H' && pos[1] <= '8' && board[pos]->player != player)
		moves.push_back(pos);


	// similarly for '\' DOWN
	f = 1; r = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[0] <= 'H' && pos[1] >= '1' && board[pos] == NULL)
	{
		moves.push_back(pos);
		f++;
		r--;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[0] <= 'H' && pos[1] >= '1' && board[pos]->player != player)
			moves.push_back(pos);

	// For '\' UP
	f = -1; r = 1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[0] >= 'A' && pos[1] <= '8' && board[pos] == NULL)
	{
		moves.push_back(pos);
		f--;
		r++;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[0] >= 'A' && pos[1] <= '8' && board[pos]->player != player) {
		moves.push_back(pos);
	}


	// '/' DOWN
	f = -1; r = -1;
	pos[0] = from[0] + f;
	pos[1] = from[1] + r;

	while (pos[0] >= 'A' && pos[1] >= '1' && board[pos] == NULL)
	{
		moves.push_back(pos);
		f--;
		r--;
		pos[0] = from[0] + f;
		pos[1] = from[1] + r;
	}

	if (pos[0] >= 'A' && pos[1] >= '1' && board[pos]->player != player)
		moves.push_back(pos);

	return moves;

}
/* END BISHOP */