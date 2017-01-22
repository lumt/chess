#ifndef ROOK_H
#define ROOK_H

#include "ChessBoard.h"
#include "ChessPieces.h"


class Rook : public Piece {
public:
	Rook(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);

	~Rook() {}
};


#endif