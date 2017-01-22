#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessBoard.h"
#include "ChessPieces.h"


class Knight : public Piece {
public:
	Knight(bool p);

	list<string> availableMoves(map<string, Piece*> &board, string from);

	~Knight() {}
};

#endif