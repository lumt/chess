#ifndef PAWN_H
#define PAWN_H

#include "ChessBoard.h"
#include "ChessPieces.h"

class Pawn : public Piece {
public:
	Pawn(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);

	~Pawn() {}
};

#endif