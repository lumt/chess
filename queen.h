#ifndef QUEEN_H
#define QUEEN_H

#include "ChessBoard.h"
#include "ChessPieces.h"

class Bishop;
class Rook;

class Queen : public Piece {
private:
	Bishop* bishop;
	Rook* rook;

public:
	Queen(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);
	~Queen() {}
};


#endif